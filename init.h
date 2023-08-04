#pragma once

#include <consoleapi.h>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "common.h"

namespace rts {

// Module nonsense. Returns 0 if success.
// https://stackoverflow.com/questions/6924195/get-dll-path-at-runtime
int getOwnLocation(char pathStr[MAX_PATH]) {
    HMODULE hm = NULL;

    if (GetModuleHandleExA(
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCSTR)&getOwnLocation, &hm) == 0)
    {
        // https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
        return GetLastError();
    }
    if (GetModuleFileNameA(hm, pathStr, sizeof(char) * MAX_PATH) == 0)
    {
        return GetLastError();
    }
    return ERROR_SUCCESS;
}

void allocConsoleStreams()
{
    if (GetConsoleWindow()) return;

    if (AllocConsole()) {
        FILE* stream;
        freopen_s(&stream, "CONIN$", "r", stdin);
        freopen_s(&stream, "CONOUT$", "w", stderr);
        freopen_s(&stream, "CONOUT$", "w", stdout);
    }
}

std::string getConsoleInput(std::string prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

void initFail(const std::ostringstream& ss) {
    std::string err = ss.str();
    dtlogf("%s\n", err.c_str());
    throw std::runtime_error(err);
}

enum InitModFeature {
    INIT_MOD_NONE = 0,
    INIT_MOD_LOG = 1,
    INIT_MOD_INI = 2,
};
// Hacky windows thing I guess
DEFINE_ENUM_FLAG_OPERATORS(InitModFeature)

struct ModPaths {
    std::string modDir;
    std::string dllName;
    std::string iniPath;
};

// TODO: Account for delayed log initialization, like based on ini settings
void initMod(std::string name, InitModFeature feat, ModPaths* paths = nullptr) {
    std::string logName = name + "_log.txt";
    std::string iniName = name + "_config.ini";

    std::ostringstream ss;

    char ownPathStr[MAX_PATH];
    int err = getOwnLocation(ownPathStr);
    if (err != ERROR_SUCCESS) {
        // Open it anywhere. Hopefully we have permission to do this.
        // If it fails, the result will be the same either way (dll load fail)
        openLog(logName.c_str());
        ss << "Error: Finding the path for mod dll failed with Windows error code " << err;
        initFail(ss);
    }

    path ownPath(ownPathStr);
    if (!std::filesystem::exists(ownPath)) {
        // Likewise. This needs to exist, otherwise we can't find ini
        openLog(logName.c_str());
        ss << "Error: The detected path for this dll does not exist: " << ownPathStr;
        initFail(ss);
    }

    std::string ownName = ownPath.filename().string();
    std::string logPath = ownPath.replace_filename(logName).string();
    std::string iniPath = ownPath.replace_filename(iniName).string();
    if (paths) {
        paths->dllName = ownName;
        paths->modDir = ownPath.remove_filename().string();
        paths->iniPath = iniPath;
    }

    if (feat & INIT_MOD_LOG) {
        openLog(logPath.c_str());
        if (!outlog) {
            ss << "Error: " << ownName << " couldn't open log file at " << logPath;
            initFail(ss);
        }
    }

    if (feat & INIT_MOD_INI) {
        if (!std::filesystem::exists(iniPath)) {
            ss << "Error: " << ownName << " requires a config file to exist at " << iniPath << std::endl << std::endl << "Either delete the dll to uninstall the mod, or put the config file in the expected location.";
            initFail(ss);
        }
    }
}

bool iniInt(const std::string& value, int& result) {
    char* err = nullptr;
    result = strtol(value.c_str(), &err, 10);
    return *err == '\0';
}

bool iniFloat(const std::string& value, float& result) {
    char* err = nullptr;
    result = strtof(value.c_str(), &err);
    return *err == '\0';
}

bool iniTime(const std::string& value, int& result) {
    // For now, just mm:ss
    int amount = 0;
    size_t mark = value.find(':');
    if (mark == std::string::npos) return iniInt(value, result);
    int mins, secs;
    if (!iniInt(value.substr(0, mark), mins) || !iniInt(value.substr(mark + 1), secs)) return false;
    result = mins * 60 + secs;
    return true;
}

bool iniPercent(const std::string& value, float& result) {
    // Remove percents. Usually callers will want to divide by 100, too.
    size_t pct = value.find_last_not_of('%');
    if (pct != std::string::npos && pct != value.size() - 1) {
        std::string trimmed = value;
        trimmed.erase(pct + 1);
        return iniFloat(trimmed, result);
    }
    else {
        return iniFloat(value, result);
    }
}

}