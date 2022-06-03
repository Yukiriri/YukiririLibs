//ver: 1.0
#pragma once
#include <Windows.h>
#include <string_view>


class RegHelper
{
public:
    RegHelper(HKEY hKey, std::string_view regPath);
    ~RegHelper();
    
    auto Set(std::string_view keyName, DWORD keyType, LPCVOID data, DWORD size)                             { return ::RegSetValueExA(_hKey, keyName.data(), 0, keyType, (BYTE*)data, size); }
    auto SetNumber(std::string_view keyName, int value)                                                     { return Set(keyName, REG_DWORD, &value, 4); }
    auto SetNumber(std::string_view keyName, INT64 value)                                                   { return Set(keyName, REG_QWORD, &value, 8); }
    auto Get(std::string_view keyName, DWORD restrictionType, LPDWORD keyType, LPVOID data, LPDWORD size)   { return ::RegGetValueA(_hKey, nullptr, keyName.data(), restrictionType, keyType, data, size); }
    auto Get(std::string_view keyName, LPDWORD keyType, LPVOID data, LPDWORD size)                          { return Get(keyName, RRF_RT_ANY, keyType, data, size); }

    constexpr static LPCSTR REG_AUTO_RUN = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";

private:
    HKEY _hKey = nullptr;

};
