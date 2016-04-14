#include <Windows.h>


DWORD	SCANkey = 0;
typedef struct {
	DWORD from;
	DWORD until;
	DWORD hash;
} tMEMSCAN;

/// <summary>Scan Memory Tools
/// </summary>
namespace aC_Memory
{
	/// <summary>Scan Address
	/// </summary>
	bool ScanAddress(const char* canBe, DWORD Address, int numBytes = 1);
	/// <summary>Memory to Hash
	/// </summary>
	DWORD Mem2Hash(BYTE *mem, int length);

	/// <summary>Scan Memory
	/// </summary>
	int	ScanMemory(tMEMSCAN* mem, int st, int maxno);
}