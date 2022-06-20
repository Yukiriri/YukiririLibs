//ver: 1.0
#pragma once
#include <Windows.h>
#include <clocale>
#include <cstdio>


class ConsoleHelper
{
public:
    template<typename... Args>
           auto Out(int x, int y, const Args&... format)                 { SetPos(x, y); ::printf(format...); }

    template<typename... Args>
           auto Out(int x, int y, int colorID, const Args&... format)    { SetColor(colorID); Out(x, y, format...); }

           auto SetPos(int x, int y)                                     { return ::SetConsoleCursorPosition(_hout, { (short)x, (short)y }); }

           auto SetColor(int colorID)                                    { return ::SetConsoleTextAttribute(_hout, colorID); }

    static auto Pause(BOOL show = TRUE)                                  { return ::system(show ? "pause" : "pause >nul"); }

    static auto Clear()                                                  { return ::system("cls"); }
    
    static auto SetTitle(LPCSTR title)                                   { return ::SetConsoleTitleA(title); }

    static auto GetWindow()                                              { return ::GetConsoleWindow(); }

    static auto SetUTF8Locale()                                          { return ::setlocale(LC_ALL, "chs.utf8"); }

    static auto SetGBKLocale()                                           { return ::setlocale(LC_ALL, "chs"); }
    
    static auto ResizeWindow(int cols, int lines);

           auto HideCursor();

private:
    HANDLE _hout = ::GetStdHandle(STD_OUTPUT_HANDLE);
};

inline auto ConsoleHelper::ResizeWindow(int cols, int lines)
{
    char command[50];
    ::wsprintfA(command, "mode con cols=%d lines=%d", cols, lines);
    ::system(command);
}

inline auto ConsoleHelper::HideCursor()
{
    CONSOLE_CURSOR_INFO cci{ 1, FALSE };
    return ::SetConsoleCursorInfo(_hout, &cci);
}
