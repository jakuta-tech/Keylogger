#include <Windows.h>
#include <winuser.h>
#include "resource.h"

// Forward functions
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), 0, (DlgProc), 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return FALSE;
	}
	return FALSE;
}