//Credits to Fleep for all the help :)
#include <iostream>
#include <windows.h>
#include <process.h>
#include "functions.h"

char FpsOpCode[] = "\x7D"; //125


void InitiateHooks(void *param)
{
	DWORD fpsAddy = GetAddy("iw4mp.exe");

	fpsAddy += 0x5F8152C;

	//iw4mp.exe+5F8152C
	while (true)
	{
		WriteToMemory(fpsAddy, FpsOpCode, 1);
		Sleep(5000);
	}
	
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD fdwReason,
	LPVOID lpReserved)
{
	
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		HANDLE handle;
		handle = (HANDLE)_beginthread(InitiateHooks, 0, 0);
		break;
	}
	return true;
}