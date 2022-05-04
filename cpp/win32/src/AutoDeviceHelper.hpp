/*
	ver: 1.0
	author: Yukins
	github: https://github.com/Yukinshell/YukinsLib
*/
#pragma once
#include <Windows.h>


class AutoDeviceHelper
{
public:
	static inline auto MouseDown(int x, int y)				{ ::mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0); }
	
	static inline auto MouseDown()							{ MouseDown(0 ,0); }

	static inline auto MouseUp(int x, int y)				{ ::mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0); }
	
	static inline auto MouseUp()							{ MouseUp(0 ,0); }

	static inline auto MouseClick(int x, int y)				{ ::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, x, y, 0, 0); }

	static inline auto MouseClick()							{ MouseClick(0 ,0); }

	static inline auto MouseMove(int x, int y)				{ ::mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0); }

	static inline auto MouseWheel(int delta = WHEEL_DELTA)	{ ::mouse_event(MOUSEEVENTF_WHEEL, 0, 0, delta, 0); }

	static inline auto KeyDown(BYTE keyCode)				{ ::keybd_event(keyCode, 0, 0, 0); }

	static inline auto KeyUp(BYTE keyCode)					{ ::keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0); }

	static inline auto KeyPress(BYTE keyCode)				{ KeyDown(keyCode); KeyUp(keyCode); }

	static inline auto KeyPressWithCtrl(BYTE keyCode)		{ KeyDown(VK_CONTROL); KeyPress(keyCode); KeyUp(VK_CONTROL); }

	static inline auto KeyPressWithShift(BYTE keyCode)		{ KeyDown(VK_SHIFT); KeyPress(keyCode); KeyUp(VK_SHIFT); }

	static inline auto KeyPressWithAlt(BYTE keyCode)		{ KeyDown(VK_MENU); KeyPress(keyCode); KeyUp(VK_MENU); }

	static        void KeyPressFromSymbol(char symbol);

};
