
#include "TrayIcon.hpp"


BOOL TrayIcon::Add(HWND hwnd, HICON hicon, LPCSTR title, int messageCode, DWORD flags)
{
	_trayIcon.cbSize = sizeof(NOTIFYICONDATAA);
	_trayIcon.hWnd = hwnd;
	_trayIcon.hIcon = hicon;
	_trayIcon.uCallbackMessage = messageCode;
	_trayIcon.uFlags = flags;
	::strcpy_s(_trayIcon.szTip, title);
	return ::Shell_NotifyIconA(NIM_ADD, &_trayIcon);
}

BOOL TrayIcon::Modify(HWND hwnd, HICON hicon, LPCSTR title, int messageCode, DWORD flags)
{
	_trayIcon.hWnd = hwnd;
	_trayIcon.hIcon = hicon;
	_trayIcon.uCallbackMessage = messageCode;
	_trayIcon.uFlags = flags;
	::strcpy_s(_trayIcon.szTip, title);
	return ::Shell_NotifyIconA(NIM_MODIFY, &_trayIcon);
}
