#include <iostream>

enum color
{
    RED, //默认是0
    GREEN, //默认是1
    BLUE //默认是2
};
/*
enum color  //可以手动指定枚举值，可以重复指定
{
    RED=2,
    GREEN,  //默认值是3，比前一个多1
    BLUE=7
};
*/

using namespace std;

int main()
{
    color cl = RED;
    color clr = color(1);
    int a = cl;
    int b = BLUE;

    cout << cl << ' ' << clr << ' ' << a << ' ' << b << '\n';

    system("pause");
    return 0;
}
