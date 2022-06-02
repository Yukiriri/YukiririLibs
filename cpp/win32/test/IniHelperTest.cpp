
#include <IniHelper.hpp>


int main()
{
    IniHelper ini(".\\IniHelperTest.ini");

    //读取例子
    int v1              =   ini("app", "int", 233);
    INT64 v2            =   ini("app", "int64", 2333);
    float v3            =   ini("app", "float", 3.1415926f);
    bool v4             =   ini("app", "bool", true);

    //写入例子
    ini("app", "int")   =   v1;
    ini("app", "int64") =   v2;
    ini("app", "float") =   v3;
    ini("app", "bool")  =   v4;
    ini("aaa", "aaa")   =   0;
    ini("aaa", "bbb")   =   0;

    //删除例子
    //删除一个key
    ini("aaa", "aaa") = nullptr;
    //删除整个app
    ini("aaa") = nullptr;

    return 0;
}
