//ver: 1.0
#pragma once
#include <Windows.h>


class TrayIcon
{
public:
    auto Add(HWND hwnd, HICON hicon, LPCSTR title, int messageCode, DWORD flags = NIF_ICON | NIF_TIP | NIF_MESSAGE);
    auto Modify(HWND hwnd, HICON hicon, LPCSTR title, int messageCode, DWORD flags);

    auto ModifyTitle(LPCSTR title);
    auto ModifyIcon(HICON hicon);
    auto ModifyMessage(int messageCode);
    auto ModifyFlags(DWORD flags);

    auto Delete();

private:
    NOTIFYICONDATAA _trayIcon{};
};

inline auto TrayIcon::ModifyTitle(LPCSTR title)
{
    ::strcpy_s(_trayIcon.szTip, title);
    return ::Shell_NotifyIconA(NIM_MODIFY, &_trayIcon);
}

inline auto TrayIcon::ModifyIcon(HICON hicon)
{
    _trayIcon.hIcon = hicon;
    return ::Shell_NotifyIconA(NIM_MODIFY, &_trayIcon);
}

inline auto TrayIcon::ModifyMessage(int messageCode)
{
    _trayIcon.uCallbackMessage = messageCode;
    return ::Shell_NotifyIconA(NIM_MODIFY, &_trayIcon);
}

inline auto TrayIcon::ModifyFlags(DWORD flags)
{
    _trayIcon.uFlags = flags;
    return ::Shell_NotifyIconA(NIM_MODIFY, &_trayIcon);
}

inline auto TrayIcon::Delete()
{
    return ::Shell_NotifyIconA(NIM_DELETE, &_trayIcon);
}

inline auto TrayIcon::Add(HWND hwnd, HICON hicon, LPCSTR title, int messageCode, DWORD flags)
{
    _trayIcon.cbSize = sizeof(NOTIFYICONDATAA);
    _trayIcon.hWnd = hwnd;
    _trayIcon.hIcon = hicon;
    _trayIcon.uCallbackMessage = messageCode;
    _trayIcon.uFlags = flags;
    ::strcpy_s(_trayIcon.szTip, title);
    return ::Shell_NotifyIconA(NIM_ADD, &_trayIcon);
}

inline auto TrayIcon::Modify(HWND hwnd, HICON hicon, LPCSTR title, int messageCode, DWORD flags)
{
    _trayIcon.hWnd = hwnd;
    _trayIcon.hIcon = hicon;
    _trayIcon.uCallbackMessage = messageCode;
    _trayIcon.uFlags = flags;
    ::strcpy_s(_trayIcon.szTip, title);
    return ::Shell_NotifyIconA(NIM_MODIFY, &_trayIcon);
}
