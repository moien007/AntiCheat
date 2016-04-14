#include <Windows.h>

namespace aC_Procces
{
	/// <summary>Is Debbuger Present
	/// </summary>
	bool DebuggerPresent;

	/// <summary>Get Current Process Module's
	/// </summary>
	int GetModules(OUT HMODULE* modules);

	/// <summary>Check Module Loaded (LoadLibrary)
	/// </summary>
	bool DllLoaded(char* moduleName);
}

