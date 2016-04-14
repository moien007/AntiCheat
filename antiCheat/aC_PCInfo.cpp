#include "stdafx.h"
#include "aC_PCInfo.h"
#include <stdio.h>
#include <Windows.h>
#include <Iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#include <stdlib.h>




char* HardwareID()
{
	HW_PROFILE_INFO hwInfo;
	TCHAR* hwid = hwInfo.szHwProfileGuid;
	return (char*)hwid;
}

char* GetMAC() // Code From NTAuthority
{
	PIP_ADAPTER_INFO AdapterInfo;
	DWORD dwBufLen = sizeof(AdapterInfo);
	char *mac_addr = (char*)malloc(17);

	AdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
	if (AdapterInfo == NULL)
	{
		return "nope";
	}

	// Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen variable
	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		AdapterInfo = (IP_ADAPTER_INFO *)malloc(dwBufLen);
		if (AdapterInfo == NULL)
		{
			return "nope";
		}
	}

	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR)
	{
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info

		free(AdapterInfo);

		return mac_addr;
	}

	return "nope";
}

char* DriveSerial()	//TODO
{
	return "Joke";
}


