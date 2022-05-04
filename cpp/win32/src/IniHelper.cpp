
#include "IniHelper.hpp"
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")


IniHelper::IniHelper(LPCSTR FileName)
{
	char buf[MAX_PATH]{};
	if (FileName[1] != ':')
	{
		::GetCurrentDirectoryA(MAX_PATH, buf);
	}
	::PathAppendA(buf, FileName);
	_iniPath = buf;

	::PathRemoveFileSpecA(buf);
	if (::PathIsDirectoryA(buf) == FALSE)
		::CreateDirectoryA(buf, nullptr);
}
