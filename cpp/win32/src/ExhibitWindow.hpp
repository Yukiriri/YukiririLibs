//ver: 1.0
#pragma once
#include <Windows.h>
#include <string>

#define winmain() WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)


class ExhibitWindow
{
public:
    ExhibitWindow(HINSTANCE appInstance);
    ExhibitWindow(const ExhibitWindow&) = delete;

    enum WINDOW_STYLE
    {
        BASIC_WINDOW =          WS_VISIBLE | WS_POPUP | WS_CAPTION | WS_SYSMENU,
        NORMAL_WINDOW =         WS_VISIBLE | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        NO_MAX_WINDOW =         WS_VISIBLE | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        MAXIMIZE_WINDOW =       WS_VISIBLE | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE,
        BORDERLESS_WINDOW =     WS_VISIBLE | WS_POPUP                           | WS_MINIMIZEBOX,
    };

    UINT Register(LPCSTR className)                                                             { return Register(className, nullptr, nullptr, nullptr); }
    UINT Register(LPCSTR className, HICON hIcon, HCURSOR hCursor, HBRUSH hBrush);

    HWND Create(LPCSTR title, DWORD style, int width, int height)                               { return Create(title, style, 0, width, height); }
    HWND Create(LPCSTR title, DWORD style, int x, int y, int width, int height)                 { return Create(title, style, 0, x, y, width, height); }
    HWND Create(LPCSTR title, DWORD style, DWORD exStyle, int width, int height);
    HWND Create(LPCSTR title, DWORD style, DWORD exStyle, int x, int y, int width, int height);

    BOOL IsExist();

private:
    HINSTANCE _appInstance = nullptr;
    HWND _hwnd = nullptr;
    std::string _className;
};
