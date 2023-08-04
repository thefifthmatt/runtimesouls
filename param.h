#pragma once

#include <stdexcept>
#include <string>
#include <thread>

#include "include/PointerChain.h"

#include "common.h"
#include "aob.h"

namespace rts {

ParamResCap* getParamResCap(const wchar_t* name) {
    // Elden Ring-specific scan.
    for (int i = 0; i < 185; i++) {
        int paramOffset = i * 0x48;
        int paramLoaded = *PointerChain::make<int>(aob::SoloParamRepository, paramOffset + 0x80);
        if (paramLoaded > 0) {
            ParamResCap* paramResCap = *PointerChain::make<ParamResCap*>(aob::SoloParamRepository, paramOffset + 0x88);
            wchar_t* containerName = (wchar_t*)&paramResCap->paramName;
            if (paramResCap->paramNameLength >= 8) {
                containerName = paramResCap->paramName;
            }
            if (wcsncmp(name, containerName, wcslen(name)) == 0) {
                return paramResCap;
            }
        }
    }
    return nullptr;
}

bool areParamsReady() {
    if (!aob::SoloParamRepository || !(*aob::SoloParamRepository)) return false;
    if (!getParamResCap(L"ThrowParam")) return false;
    return true;
}

void waitForParams(void (*callback)()) {
    while (!areParamsReady()) {
        std::this_thread::sleep_for(duration_s(1));
    }
    callback();
}

Param* getParam(const wchar_t* name) {
    ParamResCap* paramResCap = getParamResCap(name);
    if (!paramResCap) return nullptr;
    return paramResCap->paramInfo->param;
}

void* getParamRow(Param* param, int index) {
    return (void*)(param->table[index].dataOffset + (uint64_t)param);
}

void* getParamRow(Param* param, int index, int& rowId) {
    ParamRow* row = &param->table[index];
    rowId = row->id;
    return (void*)(row->dataOffset + (uint64_t)param);
}

void* findParamRow(Param* param, int rowId) {
    for (int i = 0; i < param->count; i++) {
        ParamRow* row = &param->table[i];
        if (row->id == rowId) {
            return getParamRow(param, i);
        }
    }
    return nullptr;
}

class ParamIterator {
public:
    ParamIterator(Param* param_) : param(param_) {}

    struct Iterator
    {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = std::pair<void*, int>;
        using pointer = std::pair<void*, int>*;
        using reference = std::pair<void*, int>&;

        Iterator(ParamRow* ptr, Param* param_) : ptr(ptr), param(param_) {}

        // Effectively it's a bidirectional input iterator. Arrow operator has no address to use.
        value_type operator*() { return { row(), id() }; }

        Iterator& operator++() { ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        Iterator& operator--() { ptr--; return *this; }
        Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };

        inline void* row() const { return (void*)(ptr->dataOffset + (uint64_t)param); }
        inline uint64_t addr() const { return (uint64_t)(ptr->dataOffset + (uint64_t)param); }
        inline int id() const { return ptr->id; }

    private:
        ParamRow* ptr;
        Param* param;
    };

    Iterator begin() { return Iterator(&param->table[0], param); }
    Iterator end() { return Iterator(&param->table[param->count], param); }

private:
    Param* param;
};

}