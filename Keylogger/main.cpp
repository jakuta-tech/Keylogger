#include <Windows.h>
#include <winuser.h>
#include <process.h>
#include "HookInput.h"
#include "resource.h"

#define ID_BUTTON_START                 1001
#define ID_BUTTON_STOP                  1002

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), 0, (DlgProc), 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_START:
			_beginthread(HookInput::startTracking, 0, nullptr);
			break;
		case ID_BUTTON_STOP:
			HookInput::stopTracking();
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return FALSE;
	}
	return FALSE;
}