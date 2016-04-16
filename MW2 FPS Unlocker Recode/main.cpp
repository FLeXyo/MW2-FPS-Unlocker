#include <iostream>
#include <Windows.h>


int main()
{
	DWORD fpsAddress{ 0x0638152C };
	char fps{ 0x7D }; //125
	HWND hwnd;
	DWORD pid;

	hwnd = FindWindow(NULL, L"Modern Warfare 2");
	if (!hwnd)
	{
		std::cout << "Modern Warfare 2 window not found" << std::endl;
	}
	else
	{
		GetWindowThreadProcessId(hwnd, &pid);
		HANDLE pHandle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE, 0, pid);
		std::cout << "Writing to memory..." << std::endl;
		while (true)
		{
			WriteProcessMemory(pHandle, (void*)fpsAddress, &fps, sizeof(fps), NULL);
			//ReadProcessMemory(pHandle, (void*)fpsAddress, &fps, sizeof(fps), NULL);
			Sleep(5000);
		}
		CloseHandle(pHandle);

	}
	return 0;
}