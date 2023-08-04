#pragma once

// Alternative to dinput8.h which adds linker directives, but hardcodes the system directory

#pragma comment(linker, "/export:DirectInput8Create=C:\\\\Windows\\\\System32\\\\dinput8.dll.DirectInput8Create")
#pragma comment(linker, "/export:DllCanUnloadNow=C:\\\\Windows\\\\System32\\\\dinput8.dll.DllCanUnloadNow,PRIVATE")
#pragma comment(linker, "/export:DllGetClassObject=C:\\\\Windows\\\\System32\\\\dinput8.dll.DllGetClassObject,PRIVATE")
#pragma comment(linker, "/export:DllRegisterServer=C:\\\\Windows\\\\System32\\\\dinput8.dll.DllRegisterServer,PRIVATE")
#pragma comment(linker, "/export:DllUnregisterServer=C:\\\\Windows\\\\System32\\\\dinput8.dll.DllUnregisterServer,PRIVATE")
#pragma comment(linker, "/export:GetdfDIJoystick=C:\\\\Windows\\\\System32\\\\dinput8.dll.GetdfDIJoystick")
