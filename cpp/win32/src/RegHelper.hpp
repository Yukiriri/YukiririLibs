//ver: 1.0
#pragma once
#include <Windows.h>
#include <string_view>


class RegHelper
{
public:
    RegHelper(HKEY hKey, std::string_view regPath);
    ~RegHelper();
    
    inline auto operator()(std::string_view keyName)                                            { return Helper(_hKey, keyName); }

    constexpr static LPCSTR REG_AUTO_RUN = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";

private:
    class Helper
    {
    public:
        inline auto operator=(INT value)                                                        { return SetNumber32(value); }
        inline auto operator=(UINT value)                                                       { return SetNumber32(value); }
        inline auto operator=(INT64 value)                                                      { return SetNumber64(value); }
        inline auto operator=(UINT64 value)                                                     { return SetNumber64(value); }
        inline auto operator=(SHORT value)                                                      { return SetNumber32(value); }
        inline auto operator=(USHORT value)                                                     { return SetNumber32(value); }
        inline auto operator=(LONG value)                                                       { return SetNumber32(value); }
        inline auto operator=(ULONG value)                                                      { return SetNumber32(value); }
        inline auto operator=(std::string_view value)                                           { return SetString(value); }
        inline auto operator=(std::nullptr_t)                                                   { return Delete(); }

        inline operator INT()                                                                   { return GetNumber32(); }
        inline operator UINT()                                                                  { return GetNumber32(); }
        inline operator INT64()                                                                 { return GetNumber64(); }
        inline operator UINT64()                                                                { return GetNumber64(); }
        inline operator SHORT()                                                                 { return GetNumber32(); }
        inline operator USHORT()                                                                { return GetNumber32(); }
        inline operator LONG()                                                                  { return GetNumber32(); }
        inline operator ULONG()                                                                 { return GetNumber32(); }
        inline operator std::string()                                                           { return GetString(); }

        inline LSTATUS Set(DWORD keyType, LPCVOID data, DWORD size)                             { return ::RegSetValueExA(_hKey, _keyName.data(), 0, keyType, (BYTE*)data, size); }
        inline LSTATUS Get(LPDWORD keyType, LPVOID data, LPDWORD size)                          { return Get(RRF_RT_ANY, keyType, data, size); }
        inline LSTATUS Get(DWORD restrictionType, LPDWORD keyType, LPVOID data, LPDWORD size)   { return ::RegGetValueA(_hKey, nullptr, _keyName.data(), restrictionType, keyType, data, size); }
        inline LSTATUS Delete()                                                                 { return ::RegDeleteValueA(_hKey, _keyName.data()); }

        Helper(HKEY hKey, std::string_view keyName)
            : _hKey(hKey), _keyName(keyName)
        {}

    private:
        HKEY _hKey;
        std::string_view _keyName;

        LSTATUS SetNumber32(int value)                                                          { return Set(REG_DWORD, &value, 4); }
        LSTATUS SetNumber64(INT64 value)                                                        { return Set(REG_QWORD, &value, 8); }
        LSTATUS SetString(std::string_view value)                                               { return Set(REG_SZ, value.data(), (DWORD)value.length()); }
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
