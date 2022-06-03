
#include "ExhibitWindow.hpp"


ExhibitWindow::ExhibitWindow(HINSTANCE appInstance)
    : _appInstance(appInstance)
{
    ::SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
}

UINT ExhibitWindow::Register(LPCSTR className, HICON hIcon, HCURSOR hCursor, HBRUSH hBrush)
{
    WNDCLASSEXA wndclass{};
    wndclass.cbSize =			sizeof(wndclass);
    wndclass.style =			CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wndclass.lpfnWndProc =		_MessageHandler;
    wndclass.hInstance =		_appInstance;
    wndclass.hIcon =			hIcon ? hIcon : ::LoadIconA(nullptr, (LPCSTR)IDI_APPLICATION);
    wndclass.hCursor =			hCursor ? hCursor : ::LoadCursorA(nullptr, (LPCSTR)IDC_ARROW);
    wndclass.hbrBackground =	hBrush ? hBrush : (HBRUSH)(COLOR_BACKGROUND + 1);
    wndclass.lpszClassName =	className;
    _className = className;
    return ::RegisterClassExA(&wndclass);
}

HWND ExhibitWindow::Create(LPCSTR title, DWORD style, DWORD exStyle, int width, int height)
{
    auto desk = GetDesktopWindow();
    RECT desk_rect; GetClientRect(desk, &desk_rect);
    //auto dpi = GetDpiForWindow(desk);
    //auto screen_width = (int)(desk_rect.right * (1.0f + (dpi - 96) / 24.0f * 0.25f));
    //auto screen_height = (int)(desk_rect.bottom * (1.0f + (dpi - 96) / 24.0f * 0.25f));
    auto x = (desk_rect.right - width) / 2;
    auto y = (desk_rect.bottom - height) / 2;
    return Create(title, style, exStyle, x, y, width, height);
}

HWND ExhibitWindow::Create(LPCSTR title, DWORD style, DWORD exStyle, int x, int y, int width, int height)
{
    return _hwnd = ::CreateWindowExA(exStyle, _className.c_str(), title, style, x, y, width, height, nullptr, nullptr, _appInstance, nullptr);
}

BOOL ExhibitWindow::IsExist()
{
    MSG msg;
    if (::PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return FALSE;
        ::TranslateMessage(&msg);
        ::DispatchMessageA(&msg);
    }
    return TRUE;
}

LRESULT ExhibitWindow::_MessageHandler(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
    case WM_CLOSE: ::DestroyWindow(hwnd); return 0;
    case WM_DESTROY: ::PostQuitMessage(0); return 0;
    }
    return ::DefWindowProcA(hwnd, message, wparam, lparam);
}
