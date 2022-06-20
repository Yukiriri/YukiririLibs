//ver: 1.0
#pragma once
#include <Windows.h>
#include <string>
#include <string_view>


class IniHelper
{
public:
    IniHelper(std::string_view iniPath);

    auto operator()(std::string_view appName)                                            { return Helper(_iniPath, appName, nullptr); }
    auto operator()(std::string_view appName, std::string_view keyName)                  { return Helper(_iniPath, appName, keyName.data()); }
    template<typename BASIC>
    auto operator()(std::string_view appName, std::string_view keyName, BASIC Default)   { return Helper(_iniPath, appName, keyName.data(), std::to_string(Default)); }

    auto DeleteAll()                                                                     { return ::CloseHandle(::CreateFileA(_iniPath.c_str(), GENERIC_ALL, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr)); }
    auto GetPath()                                                                       { return _iniPath.c_str(); }

private:
    class Helper
    {
    public:
        template<typename BASIC>
        auto operator=(BASIC value)                                                      { return WriteString(std::to_string(value)); }
        auto operator=(bool value)                                                       { return WriteString(value ? "true" : "false"); }
        auto operator=(LPCSTR value)                                                     { return WriteString(value); }
        auto operator=(std::nullptr_t)                                                   { return WriteString(nullptr); }

        operator INT()                                                                   { return std::stoi(ReadString()); }
        operator UINT()                                                                  { return operator INT(); }
        operator INT64()                                                                 { return std::stoll(ReadString()); }
        operator UINT64()                                                                { return std::stoull(ReadString()); }
        operator SHORT()                                                                 { return (SHORT)operator INT(); }
        operator USHORT()                                                                { return (USHORT)operator INT(); }
        operator LONG()                                                                  { return std::stol(ReadString()); }
        operator ULONG()                                                                 { return std::stoul(ReadString()); }
        operator bool()                                                                  { return ReadString() == "true"; }
        operator float()                                                                 { return std::stof(ReadString()); }
        operator double()                                                                { return std::stod(ReadString()); }
        operator std::string()                                                           { return ReadString(); }

        Helper(std::string_view iniPath, std::string_view appName, LPCSTR keyName, std::string_view Default = "")
            : _iniPath(iniPath), _appName(appName), _keyName(keyName), _Default(Default)
        {}

    private:
        std::string_view _iniPath;
        std::string_view _appName;
        LPCSTR _keyName;
        std::string_view _Default;

        auto ReadString() -> std::string
        {
            char buf[2049]{};
            ::GetPrivateProfileStringA(_appName.data(), _keyName, _Default.data(), buf, 2048, _iniPath.data());
            return buf;
        }
        BOOL WriteString(std::string_view value)
        {
            return WriteString(value.data());
        }
        BOOL WriteString(std::nullptr_t)
        {
            return ::WritePrivateProfileStringA(_appName.data(), _keyName, nullptr, _iniPath.data());
        }
    };

    std::string _iniPath;
};
