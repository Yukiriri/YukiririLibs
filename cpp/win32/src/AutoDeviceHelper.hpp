//ver: 1.0
#pragma once
#include <Windows.h>


class AutoDeviceHelper
{
public:
    static auto MouseDown(int x, int y)              { ::mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0); }
    
    static auto MouseDown()                          { MouseDown(0 ,0); }

    static auto MouseUp(int x, int y)                { ::mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0); }
    
    static auto MouseUp()                            { MouseUp(0 ,0); }

    static auto MouseClick(int x, int y)             { ::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, x, y, 0, 0); }

    static auto MouseClick()                         { MouseClick(0 ,0); }

    static auto MouseMove(int x, int y)              { ::mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0); }

    static auto MouseWheel(int delta = WHEEL_DELTA)  { ::mouse_event(MOUSEEVENTF_WHEEL, 0, 0, delta, 0); }

    static auto KeyDown(BYTE keyCode)                { ::keybd_event(keyCode, 0, 0, 0); }

    static auto KeyUp(BYTE keyCode)                  { ::keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0); }

    static auto KeyPress(BYTE keyCode)               { KeyDown(keyCode); KeyUp(keyCode); }

    static auto KeyPressWithCtrl(BYTE keyCode)       { KeyDown(VK_CONTROL); KeyPress(keyCode); KeyUp(VK_CONTROL); }

    static auto KeyPressWithShift(BYTE keyCode)      { KeyDown(VK_SHIFT); KeyPress(keyCode); KeyUp(VK_SHIFT); }

    static auto KeyPressWithAlt(BYTE keyCode)        { KeyDown(VK_MENU); KeyPress(keyCode); KeyUp(VK_MENU); }

    static void KeyPressFromSymbol(char symbol);

};
