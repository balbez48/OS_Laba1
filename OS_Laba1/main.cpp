#include "SysInfoWin.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    SysInfoWin sys_info;

    std::cout << "OS: ";
    sys_info.OsVersion();
    sys_info.ComputerName();
    sys_info.OsUser();
    std::cout << "Архитектрука: ";
    sys_info.Architect();
    sys_info.RAM();
    sys_info.InfoVirtualMemory();
    sys_info.InfoMemoryLoad();
    sys_info.InfoPageFile();
    sys_info.InfoDrivers();
    sys_info.InfoProsserors();

}