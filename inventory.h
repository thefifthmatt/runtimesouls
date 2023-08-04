#pragma once

#include "include/PointerChain.h"

#include "common.h"
#include "aob.h"

namespace rts {

void getPlayerInventory(PlayerInventory& inv) {
    void* PlayerGameData = *PointerChain::make<void*>(aob::GameDataMan, 0x08);
    // EquipGameData is 0x2B0, then 0x158
    // EquipInventoryData is embedded at x408, so we can get it from PlayerGameData
    inv.countInfo = *PointerChain::make<uint32_t>(PlayerGameData, 0x408 + 0x18);
    inv.length = *PointerChain::make<uint32_t>(PlayerGameData, 0x408 + 0x80);
    inv.startId = *PointerChain::make<int32_t>(PlayerGameData, 0x408 + 0x1C);
    // Also present at *PointerChain::make<void*>(PlayerGameData, 0x5B8, 0x10), though maybe not part of EquipInventoryData there
    inv.entries = *PointerChain::make<PlayerInventoryEntry*>(PlayerGameData, 0x408 + 0x40);
}

int getArmInventory(int arm) {
    // Based on function called in updateDurability in-game, which could be AoB'd and called directly if desired.
    // For now, this just works for -1 and -2. Arrows/bolts use a similar system with different ChrAsm offsets.
    if (arm != -1 && arm != -2) return -1;
    void* PlayerGameData = *PointerChain::make<void*>(aob::GameDataMan, 0x08);
    bool left = arm == -2;
    int armSlot = left ? 0 : 1;
    // ChrAsm is 0x320. Then vftable (8 bytes) and twohand state (4 bytes)
    int equipSlot = *PointerChain::make<int32_t>(PlayerGameData, 0x320 + 8 + 4 + (armSlot * 4));
    int equipIndex = equipSlot * 2 + armSlot;
    if (equipIndex < 0 || equipIndex >= 22) return -1;
    // EquipGameData is 0x2b0, then vftable (8 bytes)
    return *PointerChain::make<int32_t>(PlayerGameData, 0x2b0 + 8 + (equipIndex * 4));
}

bool deleteInventory(PlayerInventory& inv, int index) {
    InventoryIdInfo info{};
    PlayerInventoryEntry* entry = &inv.entries[index];
    int invId = inv.startId + index;
    info.inventoryId = invId;
    info.itemId = entry->itemId;
    int res = aob::deleteInventory(&info, 1, 0);
    return res != 0;
}

bool unequipInventory(PlayerInventory& inv, int index) {
    // EquipGameData is 0x2b0. Also add 2 for vftable below.
    int32_t* EquipGameData = PointerChain::make<int>(aob::GameDataMan, 0x08, 0x2b0).get();
    int invId = inv.startId + index;
    // This is assumed to be a weapon, so in the first 8 slots
    for (int i = 0; i < 8; i++) {
        int slotInvId = EquipGameData[2 + i];
        if (slotInvId == invId) {
            aob::unequipInventory(EquipGameData, i, 1);
            return true;
        }
    }
    return false;
}

// This is untested, but probably should work.
void equipInventory(PlayerInventory &inv, int equipSlotId, int index) {
    EquipInventoryItem info{};
    // Offset in ChrAsm, should be similar to getArmInventory calculation
    info.equipSlotId = equipSlotId;
    info.inventoryId = inv.startId + index;
    aob::equipInventory(&info);
}

int findGaitemInventory(PlayerInventory& inv, uint32_t id) {
    int count = 0;
    int max = inv.length - inv.startId;
    for (int i = 0; i <= max; i++) {
        PlayerInventoryEntry* entry = &inv.entries[i];
        if (entry->itemId > 0)
        {
            if (entry->gaitemId == id)
            {
                return i;
            }
        }
    }
    return -1;
}

bool deleteInventoryGaitem(uint32_t gaitemId) {
    PlayerInventory inv;
    getPlayerInventory(inv);
    int index = findGaitemInventory(inv, gaitemId);
    if (index < 0) return false;
    return deleteInventory(inv, index);
}

int findArmWeapon(PlayerInventory& inv, int arm) {
    int invId = getArmInventory(arm);
    int index = invId - inv.startId;
    if (index < 0 || index >= inv.length) return -1;
    // Hardcode unarmed for the time being (the game also does this in some cases)
    PlayerInventoryEntry* entry = &inv.entries[index];
    if (entry->itemId == 110000) return -1;
    return index;
}

CSWepGaitemIns* getGaitem(uint32_t gaitemId) {
    if (gaitemId == 0) return nullptr;
    GaitemRef gaitemRef;
    gaitemRef.gaitemId = gaitemId;
    aob::fillGaitem(&gaitemRef, &gaitemRef, 0);
    return gaitemRef.ins;
}

}