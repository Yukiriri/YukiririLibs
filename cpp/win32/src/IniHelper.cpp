
#include "IniHelper.hpp"
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")


IniHelper::IniHelper(std::string_view iniPath)
{
    char buf[MAX_PATH]{};
    if (iniPath[1] != ':')
    {
        ::GetCurrentDirectoryA(MAX_PATH, buf);
    }
    ::PathAppendA(buf, iniPath.data());
    _iniPath = buf;

    ::PathRemoveFileSpecA(buf);
    if (::PathIsDirectoryA(buf) == FALSE)
        ::CreateDirectoryA(buf, nullptr);
}
