#pragma once

#include <Psapi.h>

#include "Pattern16/include/Pattern16.h"

#include "common.h"

namespace aob {

// Based mainly on https://github.com/Dasaav-dsv/erfps/blob/master/src/AOB.cpp, retrofitted to use Pattern16
// rather than mem (https://github.com/0x1F9F1/mem)

static void* text = nullptr;
static size_t textSize;

bool initializeText()
{
    static bool textInit = false;
    static MODULEINFO mInfo = {};

    if (textInit) return text != nullptr;
    textInit = true;
    void* pHandle = GetCurrentProcess();
    HMODULE mod = GetModuleHandleA(NULL);
    GetModuleInformation(pHandle, mod, &mInfo, sizeof(mInfo));

    // This can be parsed structurally, especially to find multiple .text sections, but this basically works for fromsoft games.
    std::string dottext = "2E 74 65 78 74";
    uint8_t* result = (uint8_t*)Pattern16::find(mInfo.lpBaseOfDll, mInfo.SizeOfImage, dottext);
    if (!result) return false;

    textSize = *reinterpret_cast<uint32_t*>(result + 0x10);
    text = result + *reinterpret_cast<uint32_t*>(result + 0x14);
    return true;
}

enum ScanType {
    SCAN_DIRECT,
    SCAN_MOV,
    SCAN_MOVSS,
    SCAN_CALL,
    SCAN_CMP,
};

struct ScanInfo {
    // Where to put the result of the scan
    void* target = nullptr;
    // The pattern string in Pattern16 format
    std::string pattern;
    // What is being scanned, either a direct address or an instruction with a target address
    ScanType type = SCAN_DIRECT;
    // The byte offset is always applied to the result of the scan before any subsequent lookups.
    int offset = 0;
};

bool scanInfo(ScanInfo info) {
    if (!initializeText() || !info.target) return false;
    uint8_t* addr = (uint8_t*)Pattern16::find(text, textSize, info.pattern);
    if (!addr) return false;
    // Offset is applied to the result of the direct scan
    addr += info.offset;
    if (info.type != SCAN_DIRECT) {
        uint8_t* opAddr;
        uint8_t* nextInstrAddr;
        if (info.type == SCAN_MOV) {
            opAddr = addr + 3;
            nextInstrAddr = addr + 7;
        }
        else if (info.type == SCAN_MOVSS) {
            opAddr = addr + 4;
            nextInstrAddr = addr + 8;
        }
        else if (info.type == SCAN_CALL) {
            opAddr = addr + 1;
            nextInstrAddr = addr + 5;
        }
        else if (info.type == SCAN_CMP) {
            opAddr = addr + 3;
            nextInstrAddr = addr + 8;
        }
        else return false;
        addr = nextInstrAddr + *reinterpret_cast<int32_t*>(opAddr);
    }
    *((void**)info.target) = addr;
    return true;
}

template <typename ...Ts> bool scanInfos(const Ts &...args) {
    bool result = true;
    for (const ScanInfo& info : { args... }) {
        bool res = scanInfo(info);
        result &= res;
        if (!res) {
            dtlogf("Failed to find required address for %s\n", info.pattern.c_str());
        }
    }
    return result;
}

// Hooks. Converting from other formats:
// s = lambda match, mask=None: " ".join('??' if mask and mask[i] == '?' else '{:02X}'.format(c) for (i,c) in enumerate(match))
// u = lambda match: " ".join('??' if c[0] == '?' else '{:02X}'.format(int(c, 16)) for c in match.split(' '))

// -- Bases

static void** GameDataMan = nullptr;
ScanInfo GameDataManScan{ &GameDataMan, "48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 4C 8D 44 24 ?? 49 8B D6", SCAN_MOV };

static void** WorldChrManPtr = nullptr;
ScanInfo WorldChrManPtrScan{ &WorldChrManPtr, "48 8B 1D ?? ?? ?? ?? 0F 28 74 24 ?? 48 8B 7C 24 ?? 48 85 DB", SCAN_MOV };

// Also a Ptr
static void** CSEventFlagMan = nullptr;
ScanInfo CSEventFlagManScan{ &CSEventFlagMan, "48 8B 35 ?? ?? ?? ?? 0F 44 C7 89 84 24 ?? ?? ?? ?? 48 85 F6", SCAN_MOV };

static void** SoloParamRepository = nullptr;
ScanInfo SoloParamRepositoryScan{ &SoloParamRepository, "48 8B 0D ?? ?? ?? ?? 48 85 C9 0F 84 ?? ?? ?? ?? 45 33 C0 BA 90", SCAN_MOV };

static float* MinVelocity = nullptr;
ScanInfo MinVelocityScan{ &MinVelocity, "F3 0F 10 25 ?? ?? ?? ?? F3 0F 10 1D ?? ?? ?? ?? 0F 57 E6 0F 2F E3", SCAN_MOVSS };

// Should this have Ptr in the name?
static void** FD4Time = nullptr;
ScanInfo FD4TimeScan{ &FD4Time, "48 8B 05 ?? ?? ?? ?? 4C 8B 40 08 4D 85 C0 74 0D 45 0F B6 80 BE 00 00 00 E9 13 00 00 00", SCAN_MOV };

static void** CSLuaEventManager = nullptr;
ScanInfo CSLuaEventManagerScan{ &CSLuaEventManager, "48 83 3D ?? ?? ?? ?? 00 48 8B F9 0F 84 ?? ?? ?? ?? 48", SCAN_CMP };

// --- Minhook
// Example:
// if (MH_CreateHook(aob::handleDamage, &handleDamageOverride, (void**)&handleDamageOriginal) != MH_OK) hooked = false;

typedef int handleDamage_t(void*, void*, void*, uint64_t, char);
static handleDamage_t* handleDamage = nullptr;
ScanInfo handleDamageScan{ &handleDamage, "4C 8B DC 55 53 56 57 41 56 41 57 49 8D 6B 88 48 81 EC 48 01 00 00", SCAN_DIRECT };

typedef int giveItem_t(void*, rts::ItemGiveStruct*, void*, int);
static giveItem_t* giveItem = nullptr;
ScanInfo giveItemScan{ &giveItem, "8B 02 83 F8 0A", SCAN_DIRECT, -0x52 };

// Non-unique. Call right after this
typedef const wchar_t* getMessage_t(void* MsgRepository, uint32_t unk, uint32_t bndId, int msgId);
static getMessage_t* getMessage = nullptr;
ScanInfo getMessageScan{ &getMessage, "8B DA 44 8B CA 33 D2 48 8B F9 44 8D 42 6F", SCAN_CALL, 0xE };

typedef const wchar_t* sampleAnimation_t(void* hkaAnimatedSkeleton, void* boneOut, void* floatOut);
static sampleAnimation_t* sampleAnimation = nullptr;
ScanInfo sampleAnimationScan{ &sampleAnimation, "4C 8B 41 30 41 8B 40 68 45 8B 40 38 89 44 24 ?? E8", SCAN_DIRECT, -0xC };

typedef uint64_t hksEnv_t(void* scriptData, int index, void* behVar);
static hksEnv_t* hksEnv = nullptr;
ScanInfo hksEnvScan{ &hksEnv, "41 8B FE 81 FA DE 00 00 00", SCAN_DIRECT, -0x47 };

// --- To call

// (GaitemRef, pointer to gaitem id, expected type) -> original GaitemRef
// We actually want the thing it's calling, but this is good enough.
typedef int fillGaitem_t(rts::GaitemRef* gaitemRef, rts::GaitemRef* gaitem_id, uint32_t expectedType);
static fillGaitem_t* fillGaitem = nullptr;
ScanInfo fillGaitemScan{ &fillGaitem, "C1 E8 1C 83 E0 07 83 F8 05 44 0F 42 C8 45 3B C8", SCAN_DIRECT, -0x1F };

// TODO: Minhook-compatible versions?
typedef bool getEventFlag_t(void* CSEventMan, uint32_t);
static getEventFlag_t* getEventFlag = nullptr;
ScanInfo getEventFlagScan{ &getEventFlag, "44 8B 41 ?? 44 8B DA 33 D2 41 8B C3 41 F7 F0", SCAN_DIRECT };

typedef void setEventFlag_t(void* CSEventMan, uint32_t, bool);
static setEventFlag_t* setEventFlag = nullptr;
ScanInfo setEventFlagScan{ &setEventFlag, "48 89 5C 24 ?? 44 8B 49 ?? 44 8B D2 33 D2 41 8B C2 41 F7 F1", SCAN_DIRECT };

typedef int applyEffect_t(void* ChrIns, int spEffect, int unk);
static applyEffect_t* applyEffect = nullptr;
ScanInfo applyEffectScan{ &applyEffect, "0F 28 05 ?? ?? ?? ?? 48 8B F1 0F 28 0D ?? ?? ?? ?? 48 8D 48 ??", SCAN_DIRECT, -0x13 };

// (InventoryIdInfo, quantity?, some bool) -> inventory count?
typedef int deleteInventory_t(rts::InventoryIdInfo*, int32_t, uint8_t);
static deleteInventory_t* deleteInventory = nullptr;
ScanInfo deleteInventoryScan{ &deleteInventory, "45 0F B6 F0 8B DA 48 8B E9", SCAN_DIRECT, -0x1C };

typedef int unequipInventory_t(void* EquipGameData, int equipSlot, uint8_t unkArrowCond);
static unequipInventory_t* unequipInventory = nullptr;
ScanInfo unequipInventoryScan{ &unequipInventory, "8B DA 48 8B F9 83 FA 05", SCAN_DIRECT, -0x1E };

typedef int equipInventory_t(rts::EquipInventoryItem*);
static equipInventory_t* equipInventory = nullptr;
ScanInfo equipInventoryScan{ &equipInventory, "48 8B F9 48 83 C1 10 E8 ?? ?? ?? ?? 8B 4F", SCAN_DIRECT, -0xA };

typedef int emevdSwitch_t(void* EventMan, void* unk, void* EventIns);
static emevdSwitch_t* emevdSwitch = nullptr;
ScanInfo emevdSwitchScan{ &emevdSwitch, "49 8B 80 D0 00 00 00 49 8B F8 8B 10 81 FA E8 03 00 00", SCAN_DIRECT, -0xA };

typedef void luaWarp_01_t(void* LuaEventMan, void* unk, int id);
static luaWarp_01_t* luaWarp_01 = nullptr;
ScanInfo luaWarp_01Scan{ &luaWarp_01, "C3 ?? ?? ?? ?? ?? ?? 57 48 83 EC ?? 48 8B FA 44", SCAN_DIRECT, 0x2 };

// For testing new game versions. Contains all scans unless I forgot to add them. It is recommended to scan only what what you use.
bool scanAll() {
    return scanInfos(
        GameDataManScan, WorldChrManPtrScan, SoloParamRepositoryScan, MinVelocityScan, FD4TimeScan, CSLuaEventManagerScan,
        handleDamageScan, giveItemScan, getMessageScan, sampleAnimationScan, hksEnvScan,
        fillGaitemScan, getEventFlagScan, setEventFlagScan, applyEffectScan,
        deleteInventoryScan, unequipInventoryScan, equipInventoryScan, emevdSwitchScan, luaWarp_01Scan);
}

}