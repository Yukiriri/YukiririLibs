
#include <ConsoleHelper.hpp>
#include <iostream>
using std::cout;
using std::wcout;

int main()
{
    ConsoleHelper ch;

    //修改控制台窗口大小，会清空控制台屏幕现有内容
    ch.ResizeWindow(100, 40);

    //输出例子
    ch.Out(5, 5, "一串文字");
    ch.Out(5, 6, "一些变量:%d  %f  %I64d  %I64u", 233, 233.f, 2333333333333333LL, -1LL);
    ch.Out(5, 7, 14, "更改颜色后的一些变量:%d  %f  %I64d  %I64u", 233, 233.f, 2333333333333333LL, -1LL);

    ch.SetPos(0, 9);
    //cout << u8"utf8中文，在更改locale之前输出是乱码\n";
    //wcout << L"utf16中文，在更改locale之前输出失败\n";
    //这个只需要调用一次
    ch.SetUTF8Locale();
    cout << u8"utf8中文，现在可以正常输出\n";
    wcout << L"utf16中文，现在可以正常输出\n";

    //隐藏控制台闪烁光标，做控制台游戏的时候效果最佳
    ch.HideCursor();

    //按任意键退出程序
    ch.Pause(); //ConsoleHelper::Pause();

    return 0;
}
