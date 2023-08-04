#pragma once

#include <filesystem>
#include <string>
#include <thread>

#include "common.h"

using path = std::filesystem::path;

namespace rts {

// Time to use this horrid API
// Usage for config files: std::thread iniThread(rts::watchChanges, readIniFile, paths.iniPath); iniThread.detach();

void watchChanges(void (*callback)(std::string), std::string filePath) {
	path file(filePath);
	std::filesystem::file_time_type mtime = std::filesystem::last_write_time(file);

	const wchar_t* parent = file.parent_path().c_str();
	void* handle = FindFirstChangeNotification(parent, false, FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE);

	if (!handle || handle == INVALID_HANDLE_VALUE) {
		dtlogf("Failed to initialize file watcher for %s: error %d\n", filePath.c_str(), GetLastError());
		return;
	}

	while (true) {
		int status = WaitForSingleObject(handle, INFINITE);
		if (status != WAIT_OBJECT_0) {
			dtlogf("Unexpected result from file watcher for %s: %d, error %d\n", filePath.c_str(), status, GetLastError());
			return;
		}
		if (std::filesystem::exists(file)) {
			std::filesystem::file_time_type newMtime = std::filesystem::last_write_time(file);
			if (newMtime > mtime) {
				callback(filePath);
				// Don't allow 60fps file updates - provide a more sensible way to get data in that case.
				std::this_thread::sleep_for(duration_s(0.3f));
			}
			mtime = newMtime;
		}
		if (!FindNextChangeNotification(handle)) {
			dtlogf("Failed to get next change from file watcher for %s: error %d\n", filePath.c_str(), GetLastError());
			return;
		}
	}
}

}