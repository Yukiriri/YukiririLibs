
#include "RegHelper.hpp"


RegHelper::RegHelper(HKEY hKey, std::string_view regPath)
{
    ::RegOpenKeyExA(hKey, regPath.data(), 0, KEY_ALL_ACCESS, &_hKey);
}

RegHelper::~RegHelper()
{
    ::RegCloseKey(_hKey);
}
