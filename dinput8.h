#pragma once

#include "common.h"
#include <unknwn.h>

// Alternative to dinput8link.h which should be called from DllMain, even though doing
// basically anything in DllMain violates a ton of Windows guidelines. Reference:
// https://github.com/pampersrocker/DInput8HookingExample
// https://gist.github.com/NotAdam/389ed8173afffb58ad13431ad01067af

static HRESULT(WINAPI* OrigDirectInput8Create)(
    HINSTANCE hinst,
    DWORD dwVersion,
    REFIID riidltf,
    LPVOID* ppvOut,
    LPUNKNOWN punkOuter
    );

extern "C" __declspec(dllexport) HRESULT WINAPI DirectInput8Create(
    HINSTANCE hinst,
    DWORD dwVersion,
    REFIID riidltf,
    LPVOID * ppvOut,
    LPUNKNOWN punkOuter
)
{
    return OrigDirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}

BOOL LoadDinput8() {
    char lib_path[MAX_PATH];
    GetSystemDirectoryA(lib_path, MAX_PATH);
    strcat_s(lib_path, "\\dinput8.dll");
    auto lib = LoadLibraryA(lib_path);
    if (!lib)
    {
        return FALSE;
    }
    *(void**)&OrigDirectInput8Create = (void*)GetProcAddress(lib, "DirectInput8Create");
    return TRUE;
}
