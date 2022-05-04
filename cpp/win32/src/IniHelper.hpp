/*
	ver: 1.0
	author: Yukins
	github: https://github.com/Yukinshell/YukinsLib
*/
#pragma once
#include <Windows.h>
#include <string>
#include <string_view>


class IniHelper
{
public:
	IniHelper(LPCSTR absolutePath);

	inline auto operator()(std::string_view appName)											{ return Helper(_iniPath, appName, nullptr); }
	inline auto operator()(std::string_view appName, std::string_view keyName)					{ return Helper(_iniPath, appName, keyName.data()); }
	template<typename BASIC>
	inline auto operator()(std::string_view appName, std::string_view keyName, BASIC Default)	{ return Helper(_iniPath, appName, keyName.data(), Default); }

	inline auto DeleteAll()																		{ return ::CloseHandle(::CreateFileA(_iniPath.c_str(), GENERIC_ALL, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr)); }
	inline auto GetPath()																		{ return _iniPath.c_str(); }

private:
	class Helper
	{
	public:
		template<typename BASIC>
		inline auto operator=(BASIC value)														{ return WriteString(std::to_string(value)); }
		inline auto operator=(bool value)														{ return WriteString(value ? "true" : "false"); }
		inline auto operator=(LPCSTR value)														{ return WriteString(value); }
		inline auto operator=(std::nullptr_t)													{ return WriteString(nullptr); }

		inline operator INT()																	{ return std::stoi(ReadString()); }
		inline operator UINT()																	{ return (UINT)operator INT(); }
		inline operator INT64()																	{ return std::stoll(ReadString()); }
		inline operator UINT64()																{ return std::stoull(ReadString()); }
		inline operator SHORT()																	{ return (SHORT)operator INT(); }
		inline operator USHORT()																{ return (USHORT)operator INT(); }
		inline operator LONG()																	{ return std::stol(ReadString()); }
		inline operator ULONG()																	{ return std::stoul(ReadString()); }
		inline operator bool()																	{ return ReadString() == "true"; }
		inline operator float()																	{ return std::stof(ReadString()); }
		inline operator double()																{ return std::stod(ReadString()); }
		inline operator std::string()															{ return ReadString(); }

		Helper(std::string_view iniPath, std::string_view appName, LPCSTR keyName) :
			_iniPath(iniPath), _appName(appName), _keyName(keyName), _Default("")
		{}

		template<typename BASIC>
		Helper(std::string_view iniPath, std::string_view appName, LPCSTR keyName, BASIC Default) :
			_iniPath(iniPath), _appName(appName), _keyName(keyName), _Default(std::to_string(Default))
		{}

		Helper(std::string_view iniPath, std::string_view appName, LPCSTR keyName, bool Default) :
			_iniPath(iniPath), _appName(appName), _keyName(keyName), _Default(Default ? "true" : "false")
		{}

	private:
		std::string_view _iniPath;
		std::string_view _appName;
		LPCSTR _keyName;
		std::string _Default;

		inline auto ReadString() -> std::string
		{
			auto buf = new char[2048]{};
			::GetPrivateProfileStringA(_appName.data(), _keyName, _Default.c_str(), buf, 2048, _iniPath.data());
			std::string str = buf;
			delete[] buf;
			return str;
		}
		inline BOOL WriteString(LPCSTR value)
		{
			return ::WritePrivateProfileStringA(_appName.data(), _keyName, value, _iniPath.data());
		}
		inline BOOL WriteString(const std::string& value)
		{
			return WriteString(value.c_str());
		}
	};

	std::string _iniPath;
};
