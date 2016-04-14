#include "stdafx.h"
#include "aC_Windows.h"
#include <Windows.h>


int WINAPI GetWindowText(
	_In_  HWND   hWnd,
	_Out_ LPTSTR lpString,
	_In_  int    nMaxCount
	);


char* GetProcWindowText(HWND hWnD) // Get Process Window Caption\Text
{
	int winTextLength = GetWindowTextLength(hWnD);
	WCHAR winText[20];
	GetWindowText(hWnD, winText, winTextLength);
	return (char*)winText;
}

bool WindowExist(LPCWSTR WindowName, OUT HWND Prc = NULL) // Check Window By This Name Exist 
{
	HWND proc = FindWindow(NULL, WindowName);

	if (proc != NULL)
	{
		Prc = proc;
		return true;
	}

	return false;
}