#include <Windows.h>

namespace aC_Windows
{
	/// <summary>Get Process Window Text
	/// </summary>
	char* GetProcWindowText(HWND hWnD);

	/// <summary>Check Any Program by This Window Exist
	/// </summary>
	bool WindowExist(LPCWSTR WindowName);
}

