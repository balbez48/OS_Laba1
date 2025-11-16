#include <windows.h>
#include <psapi.h>
#include <iostream>
#pragma once


class SysInfoWin {
public:
	void OsVersion();
	void OsUser();
	void ComputerName();
	void Architect();
	void RAM();
	void InfoVirtualMemory();
	void InfoMemoryLoad();
	void InfoPageFile();
	void InfoDrivers();
	void InfoProsserors();
};