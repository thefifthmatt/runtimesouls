#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <cstdint>
#include <cstdio>
#include <filesystem>

typedef std::chrono::time_point<std::chrono::steady_clock> clock_time;
typedef std::chrono::duration<float> duration_s;
using path = std::filesystem::path;

// https://stackoverflow.com/questions/2354784/attribute-formatprintf-1-2-for-msvc
#undef FORMAT_STRING
#if _MSC_VER >= 1400
# include <sal.h>
# if _MSC_VER > 1400
#  define FORMAT_STRING(p) _Printf_format_string_ p
# else
#  define FORMAT_STRING(p) __format_string p
# endif /* FORMAT_STRING */
#else
# define FORMAT_STRING(p) p
#endif /* _MSC_VER */

namespace rts {

FILE* outlog;
// Informally: above base level, 0 is everything, 1 is info, 2 is debug
int logLevel = 0;

void dlogf(FORMAT_STRING(const char* format), ...) {
    if (!outlog) return;
    va_list argptr;
    va_start(argptr, format);
    vfprintf(outlog, format, argptr);
    // Extra cost, but don't lose logs in case of crashes
    fflush(outlog);
    va_end(argptr);
}

// I guess for debug mode.
void ddlogf(FORMAT_STRING(const char* format), ...) {
    if (!outlog || logLevel < 2) return;
    va_list argptr;
    va_start(argptr, format);
    vfprintf(outlog, format, argptr);
    fflush(outlog);
    va_end(argptr);
}

void dtlogf(FORMAT_STRING(const char* format), ...) {
    if (!outlog) return;
    va_list argptr;
    va_start(argptr, format);

    std::time_t t = std::time(nullptr);
    struct tm newtime;
    localtime_s(&newtime, &t);
    char mbstr[20];
    if (std::strftime(mbstr, sizeof(mbstr), "%F %T", &newtime)) {
        fprintf(outlog, "[%s] ", mbstr);
    }
    // Note: Newline still required in format string
    vfprintf(outlog, format, argptr);
    fflush(outlog);
    va_end(argptr);
}

void openLog(const char* path) {
    outlog = _fsopen(path, "a", _SH_DENYNO);
    if (outlog) {
        dlogf("--------------------------------------------------------------------------------\n");
    }
}

// -- Inventory

struct InventoryIdInfo {
    // Has a bunch of stuff, but deleteInventory only accesses 0x48 inventory id and 0x4C item id
    uint8_t unk00[0x48];
    int32_t inventoryId;
    int32_t itemId;
};

struct EquipInventoryItem {
    uint8_t unk00[0x8];
    uint32_t equipSlotId;
    uint8_t unk0C[0x4C];
    // 0x58
    uint32_t inventoryId;
};

struct CSWepGaitemIns {
    void* vftable;
    uint32_t gaitemId;
    int32_t itemId;
    uint32_t durability;
    uint32_t counter;
    // AoW-related
    void* unk18;
    void* unk20;
    uint32_t unk28;
    uint32_t unk2C;
};

// For use with lookup function
struct GaitemRef {
    uint32_t gaitemId;
    CSWepGaitemIns* ins;
    uint32_t itemId;
    uint32_t unk20;
};

struct PlayerInventoryEntry {
    uint32_t gaitemId;
    uint32_t itemId;
    uint32_t quantity;
    int32_t displayId;
    int32_t unk10; // -1
};

struct PlayerInventory {
    uint32_t countInfo;
    uint32_t length;
    int32_t startId;
    PlayerInventoryEntry* entries;
};

struct ItemInfo {
    uint32_t itemId;
    uint32_t itemQuantity;
    uint32_t itemRelayValue;
    uint32_t itemAshOfWar;
};

struct ItemGiveStruct {
    uint32_t count;
    ItemInfo items[10];
};

// -- Damage

struct AttackDamageInfo {
    float physDamage;
    float magDamage;
    float fireDamage;
    float thunDamage;
    float darkDamage;
    // By default, 100 100 100 100 100 (0)
    uint16_t unk14[6];
    float unk20;
    uint32_t unk24;
    float unk28;
    int unk2C;
    int unk30; // 0
    int unk34; // 0
    // -1 for some spells
    int attackBehaviorId;
    float unk3C;
    int attackId;
    int unk44; // 1
    // -1 right weapon, -2 left weapon, -4 bolt, -6 arrow
    int16_t equipSlot;
    int16_t unk4A; // -1
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    uint8_t unk5C[0xE8];
    // 0x144 has the weapon id, so we can sorta verify it matches the current thing in the inventory slot
    uint32_t weaponId;
    uint8_t unk148[0xE0];
    // Then after this, a bunch of numbers.
    // The total length is 0x2b8, and this is embedded at offset 0x38 in an array of bigger structs of length 0x2f0.
    int combinedDamage; // 0x228
};

// -- Params

struct ParamRow {
    uint32_t id;
    uint32_t pad04;
    uint32_t dataOffset;
    uint32_t pad0C;
    uint32_t nameOffset;
    uint32_t pad14;
};

// Header and actual param contents.
struct Param {
    uint32_t nameOffset;
    uint8_t unk04[0x6];
    uint16_t count;
    uint8_t unk0C[0x4];
    uint64_t paramTypeOffset;
    uint8_t unk18[0x18];
    uint32_t dataOffset;
    uint8_t unk34[0xC];
    ParamRow table[];
};

struct ParamInfo {
    uint8_t unk00[0x18];
    wchar_t* paramName;
    uint8_t unk20[0x60];
    Param* param;
};

struct ParamResCap {
    uint8_t unk00[0x18];
    wchar_t* paramName;
    uint8_t unk20[0x8];
    uint32_t paramNameLength;
    uint8_t unk2C[0x54];
    ParamInfo* paramInfo;
};

// -- Speffects

// via ERSkeletonMan
struct SpEffectNode {
    void* pSpEffectParam;
    int id;
    int unk00[9];
    SpEffectNode* next;
    SpEffectNode* previous;
    float effectEndurance;
    float motionInterval;
    float effectLife;
    float unk01[3];
    int unk02;
};

}

// Allow unnamespaced access by default
using rts::dlogf;
using rts::ddlogf;
using rts::dtlogf;
