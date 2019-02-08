//============================================================================
// Name        : PlatformDetect.h
// Author      : alexandru.mihail
// Version     : 1.0
// Copyright   : Alexandru Mihail
// Description : Header file providing OS and version name detection.
//============================================================================
#ifndef PLATFORMDETECT_H_
#define PLATFORMDETECT_H_

#ifdef __linux__
#include <sys/utsname.h>
bool isLinuxBuild = true;
struct utsname unameData;
int LinuxInfo = uname(&unameData);

#elif _WIN32
#include <windows.h>
bool isLinuxBuild = false;

#else

#endif

#include <cstdio>

void getOS()
{
#ifdef __linux__
	printf("Running on %s %s %s\n",unameData.sysname,unameData.nodename,unameData.release);

#endif

#ifdef _WIN32
	OSVERSIONINFOEX info;
	ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
	info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx((LPOSVERSIONINFO) &info);
	printf("Running on Windows %lu.%lu\n", info.dwMajorVersion,
			info.dwMinorVersion);
#endif
#if !defined(__linux__) && !defined(_WIN32)
	printf("UNSUPPORTED PLATFORM!");
#endif
}

#endif /* PLATFORMDETECT_H_ */
