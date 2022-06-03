
#include <RegHelper.hpp>


int main()
{
    RegHelper reg(HKEY_CURRENT_USER, "Software\\测试项目1");

    reg("t1")  = 233;
    reg("t2")  = "233";
    reg("t3")  = nullptr;

    int a      = reg("t1");

    return 0;
}
