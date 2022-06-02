
#include <ExhibitWindow.h>
#include <iostream>
using std::cout;
using std::wcout;


int winmain()
{
    ExhibitWindow ew(hInstance);

    ew.Register("233");
    
    //普通窗口
    ew.Create("2333", ew.NORMAL_WINDOW, 1000, 800);
    
    //可调整尺寸窗口
    //ew.Create("2333", ew.NORMAL_WINDOW | WS_THICKFRAME, 1000, 800);
    
    //初始最大化窗口
    //ew.Create("2333", ew.MAXIMIZE_WINDOW, 1000, 800);
    
    //全屏程序窗口
    //RECT desk_rect; GetClientRect(GetDesktopWindow(), &desk_rect);
    //ew.Create("2333", ew.BORDERLESS_WINDOW, desk_rect.right, desk_rect.bottom);

    while (ew.IsExist())
    {
        //做你的事
        Sleep(1);
    }

    return 0;
}
