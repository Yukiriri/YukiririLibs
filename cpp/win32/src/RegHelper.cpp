
#include "RegHelper.hpp"


RegHelper::RegHelper(HKEY hKey, std::string_view regPath)
{
    if (::RegOpenKeyExA(hKey, regPath.data(), 0, KEY_ALL_ACCESS, &_hKey) == ERROR_FILE_NOT_FOUND)
    {
        ::RegCreateKeyA(hKey, regPath.data(), &_hKey);
    }
}

RegHelper::~RegHelper()
{
    ::RegCloseKey(_hKey);
}
