#include "stdafx.h"
#include "aC_Process.h"
#include <Windows.h>
#include <Psapi.h>
#include <tlhelp32.h>
#include <stdio.h>
#include "aC_Memory.h"

using namespace std;

bool DllLoaded(char* moduleName)
{
	return GetModuleHandle((LPCWSTR)moduleName);
}

int GetModules(OUT HMODULE* modules)
{
	DWORD currentProcces = 0;
	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me32;

	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, currentProcces);

	if (hModuleSnap == INVALID_HANDLE_VALUE)
	{
		return (FALSE);
	}

	me32.dwSize = sizeof(MODULEENTRY32);

	if (!Module32First(hModuleSnap, &me32))
	{
		CloseHandle(hModuleSnap);
		return (FALSE);
	}
	
	int a = 0;

	do
	{
		modules[a] = (HMODULE)me32.szModule;
		a++;
		
	} while (Module32Next(hModuleSnap, &me32));

	CloseHandle(hModuleSnap);
	a = NULL;
	

	return 0;
}

bool DebuggerPresent()
{
	return IsDebuggerPresent;
}
