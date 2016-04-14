#include <afxwin.h>
#include <Windows.h>

namespace aC_Screenshot
{
	/// <summary>Get FullScreen Screenshot of Desktop
	/// </summary>
	HBITMAP FullSreenshot();

	/// <summary>Get ScreenShot of Window
	/// </summary>
	HBITMAP WindowScreenshot(HWND hWnD);
}