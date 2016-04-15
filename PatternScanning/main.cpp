//Credits to Fleep for all the help :)
#include <iostream>
#include <windows.h>
#include "functions.h"

char FpsOpCode[] = "\x7D";

void InitiateHooks()
{
	DWORD fpsAddy = GetAddy("iw4mp.exe");

	fpsAddy += 0x5F8152C;

	//MsgBoxAddy(fpsAddy);
	//iw4mp.exe+5F8152C
	WriteToMemory(fpsAddy, FpsOpCode, 1);
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD fdwReason,
	LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		//MessageBoxA(NULL, "Attatched Successfully", "", 0);
		InitiateHooks();
		break;
	}
	return true;
}