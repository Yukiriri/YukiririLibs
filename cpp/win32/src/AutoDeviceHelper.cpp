
#include "AutoDeviceHelper.hpp"


void AutoDeviceHelper::KeyPressFromSymbol(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
		KeyPress(symbol);
	else if (symbol >= 'a' && symbol <= 'z')
		KeyPress(symbol - 32);
	else if (symbol >= 'A' && symbol <= 'Z')
		KeyPressWithShift(symbol);
	else switch (symbol)
	{
	case ' ': KeyPress(32); break;
	case '\t': KeyPress(9); break;
	case '\n': KeyPress(13); break;
	case '+': KeyPress(107); break;
	case '-': KeyPress(109); break;
	case '*': KeyPress(106); break;
	case '/': KeyPress(111); break;
	case '=': KeyPress(187); break;
	case '[': KeyPress(219); break;
	case ']': KeyPress(221); break;
	case '\\': KeyPress(220); break;
	case ';': KeyPress(186); break;
	case '\'': KeyPress(222); break;
	case ',': KeyPress(188); break;
	case '.': KeyPress(190); break;
	case '~': KeyPressWithShift(192); break;
	case '!': KeyPressWithShift(49); break;
	case '@': KeyPressWithShift(50); break;
	case '#': KeyPressWithShift(51); break;
	case '$': KeyPressWithShift(52); break;
	case '%': KeyPressWithShift(53); break;
	case '^': KeyPressWithShift(54); break;
	case '&': KeyPressWithShift(55); break;
	case '(': KeyPressWithShift(57); break;
	case ')': KeyPressWithShift(48); break;
	case '_': KeyPressWithShift(189); break;
	case '{': KeyPressWithShift(219); break;
	case '}': KeyPressWithShift(221); break;
	case '|': KeyPressWithShift(220); break;
	case ':': KeyPressWithShift(186); break;
	case '"': KeyPressWithShift(222); break;
	case '<': KeyPressWithShift(188); break;
	case '>': KeyPressWithShift(190); break;
	case '?': KeyPressWithShift(191); break;
	}
}
