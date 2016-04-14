#include "stdafx.h"
#include "aC_Memory.h"
#include <Windows.h>
#include "aC_Windows.h"


bool ScanAddress(const char* canBe, DWORD Address, int numBytes = 1)
{
	if (memcmp(canBe, (void*)Address, numBytes) != 0)
	{
		return true;
	}

	
	return false;
}

DWORD Mem2Hash(BYTE *mem, int length)
{
	DWORD dwHash;
	dwHash = 0;
	do
	{
		dwHash = _rotr((DWORD)dwHash, 13);
		dwHash += *mem++;
	} while (--length);
	return dwHash;
}

int	ScanMemory(tMEMSCAN* mem, int st, int maxno)
{
	DWORD from, until, hash;
	int i;
	for (i = st; i<maxno; i++) {
		from = mem->from  ^ SCANkey;
		until = mem->until ^ SCANkey;

		hash = Mem2Hash((PBYTE)from, (int)(until - from + 1));
		if (hash != mem->hash) {
			break;
		}
		mem = (tMEMSCAN *)((DWORD)mem + sizeof(tMEMSCAN));		// next entry
	}

	return i;
}