#include "SysInfoWin.h"

void SysInfoWin::OsVersion()
{
    HKEY hKey;
    RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &hKey);

    char name[256];
    DWORD size = sizeof(name);
    RegQueryValueExA(hKey, "ProductName", NULL, NULL, (LPBYTE)name, &size);

    std::cout << name << std::endl;
    RegCloseKey(hKey);
}

void SysInfoWin::OsUser()
{
    char user_name[256];
    DWORD size = sizeof(user_name);
    GetUserNameA(user_name, &size);
    std::cout << "Имя пользователя: " << user_name << std::endl;
}

void SysInfoWin::ComputerName()
{
    char comp_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(comp_name);
    GetComputerNameA(comp_name, &size);
    std::cout << "Имя компьютера: " << comp_name << std::endl;
}

void SysInfoWin::Architect()
{
    SYSTEM_INFO sys_info;
    GetNativeSystemInfo(&sys_info);

    switch (sys_info.wProcessorArchitecture) {
      case PROCESSOR_ARCHITECTURE_AMD64: {
        std::cout << "x64" << std::endl;
      } break;
      case PROCESSOR_ARCHITECTURE_INTEL: {
        std::cout << "x86" << std::endl;
      } break;
      case PROCESSOR_ARCHITECTURE_ARM: {
        std::cout << "ARM" << std::endl;
      } break;
      case PROCESSOR_ARCHITECTURE_ARM64: {
        std::cout << "ARM64" << std::endl;
      } break;
      case PROCESSOR_ARCHITECTURE_IA64: {
        std::cout << "IA64" << std::endl;
      } break;
      default:
        std::cout << "Неизвестная архитектура" << std::endl;
    }
}

void SysInfoWin::RAM()
{
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);
    std::cout << "Физическая память: " << mem.ullTotalPhys / (1024 * 1024 * 1024) << " GB" << std::endl;
}

void SysInfoWin::InfoVirtualMemory()
{
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);
    std::cout << "Виртуальная память: " << mem.ullTotalVirtual / (1024 * 1024 * 1024) << " GB" << std::endl;
}

void SysInfoWin::InfoMemoryLoad()
{
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);
    std::cout << "Использование памяти: " << mem.dwMemoryLoad << "%" << std::endl;
}

void SysInfoWin::InfoPageFile()
{
    PERFORMANCE_INFORMATION perf;
    perf.cb = sizeof(perf);
    GetPerformanceInfo(&perf, sizeof(perf));
    std::cout << "Файл подкачки: " << (perf.PageSize * perf.CommitLimit) / (1024 * 1024 * 1024) << " GB" << std::endl;
}

void SysInfoWin::InfoProsserors()
{
    SYSTEM_INFO sys;
    GetSystemInfo(&sys);
    std::cout << "Ядер процессора: " << sys.dwNumberOfProcessors << std::endl;
}

void SysInfoWin::InfoDrivers()
{
    for (char drive = 'A'; drive <= 'Z'; drive++) {  
        std::string root = std::string(1, drive) + ":\\";
        ULARGE_INTEGER total, free;

        if (GetDiskFreeSpaceExA(root.c_str(), &free, &total, NULL)) {
            std::cout << "Диск " << drive << ": " << free.QuadPart / (1024 * 1024 * 1024) << " / " << total.QuadPart / (1024 * 1024 * 1024) << " GB" << std::endl;
        }
    }
}
