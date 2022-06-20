//ver: 1.0
#pragma once
#include <Windows.h>
#include <string_view>


class RegHelper
{
public:
    RegHelper(HKEY hKey, std::string_view regPath);
    ~RegHelper();
    
    auto operator()(std::string_view keyName)                                            { return Helper(_hKey, keyName); }

    static constexpr auto REG_AUTO_RUN = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";

private:
    class Helper
    {
    public:
        auto operator=(INT value)                                                        { return SetNumber32(value); }
        auto operator=(UINT value)                                                       { return SetNumber32(value); }
        auto operator=(INT64 value)                                                      { return SetNumber64(value); }
        auto operator=(UINT64 value)                                                     { return SetNumber64(value); }
        auto operator=(SHORT value)                                                      { return SetNumber32(value); }
        auto operator=(USHORT value)                                                     { return SetNumber32(value); }
        auto operator=(LONG value)                                                       { return SetNumber32(value); }
        auto operator=(ULONG value)                                                      { return SetNumber32(value); }
        auto operator=(std::string_view value)                                           { return SetString(value); }
        auto operator=(std::nullptr_t)                                                   { return Delete(); }

        operator INT()                                                                   { return GetNumber32(); }
        operator UINT()                                                                  { return GetNumber32(); }
        operator INT64()                                                                 { return GetNumber64(); }
        operator UINT64()                                                                { return GetNumber64(); }
        operator SHORT()                                                                 { return GetNumber32(); }
        operator USHORT()                                                                { return GetNumber32(); }
        operator LONG()                                                                  { return GetNumber32(); }
        operator ULONG()                                                                 { return GetNumber32(); }
        operator std::string()                                                           { return GetString(); }

        LSTATUS Set(DWORD keyType, LPCVOID data, DWORD size)                             { return ::RegSetValueExA(_hKey, _keyName.data(), 0, keyType, (BYTE*)data, size); }
        LSTATUS Get(LPDWORD keyType, LPVOID data, LPDWORD size)                          { return Get(RRF_RT_ANY, keyType, data, size); }
        LSTATUS Get(DWORD restrictionType, LPDWORD keyType, LPVOID data, LPDWORD size)   { return ::RegGetValueA(_hKey, nullptr, _keyName.data(), restrictionType, keyType, data, size); }
        LSTATUS Delete()                                                                 { return ::RegDeleteValueA(_hKey, _keyName.data()); }

        Helper(HKEY hKey, std::string_view keyName)
            : _hKey(hKey), _keyName(keyName)
        {}

    private:
        HKEY _hKey;
        std::string_view _keyName;

        LSTATUS SetNumber32(int value)                                                   { return Set(REG_DWORD, &value, 4); }
        LSTATUS SetNumber64(INT64 value)                                                 { return Set(REG_QWORD, &value, 8); }
        LSTATUS SetString(std::string_view value)                                        { return Set(REG_SZ, value.data(), (DWORD)value.length()); }
        int GetNumber32()
        {
            DWORD type, size; int value = 0;
            Get(&type, &value, &size);
            return value;
        }
        INT64 GetNumber64()
        {
            DWORD type, size; INT64 value = 0;
            Get(&type, &value, &size);
            return value;
        }
        std::string GetString()
        {
            DWORD type, size; DWORD str_len = 1;
            Get(&type, nullptr, &str_len);
            std::string value(str_len, '\0');
            Get(&type, value.data(), &size);
            return value;
        }
    };

    HKEY _hKey = nullptr;
};
