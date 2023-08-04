#pragma once

#include "include/PointerChain.h"

#include "common.h"
#include "aob.h"

namespace rts {

void* getPlayerIns() {
    void* chrMan = *aob::WorldChrManPtr;
    if (!chrMan) return nullptr;
    return *PointerChain::make<void*>(chrMan, 0x1E508);
}

inline std::vector<int> getSpEffectIds(void* ChrIns)
{
    // via ERSkeletonMan
    SpEffectNode* current = PointerChain::make<SpEffectNode*>(ChrIns, 0x178, 0x8u).dereference(nullptr);
    std::vector<int> ids;
    while (!!current) {
        ids.push_back(current->id);
        current = current->next;
    }
    return ids;
}

bool hasSpEffectId(void* ChrIns, int id) {
    SpEffectNode* current = PointerChain::make<SpEffectNode*>(ChrIns, 0x178, 0x8u).dereference(nullptr);
    while (!!current) {
        if (current->id == id) return true;
        current = current->next;
    }
    return false;
}

void printSpEffects(void* ChrIns) {
    // Always on speffects for c0000: 100620 (right) 100621 (left)
    std::vector<int> sps = getSpEffectIds(ChrIns);
    for (int sp : sps) {
        dlogf(" %d", sp);
    }
    dlogf("\n");
}

}