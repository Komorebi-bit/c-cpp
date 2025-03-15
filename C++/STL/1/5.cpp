#include <iostream>

using namespace std;

/*
给定年份y和整数d，求出这一年的第d天是几月几日

样例输入：
2015
80
样例输出：
3
21
*/

int main()
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y = 0,d = 0;
    scanf("%d%d", &y, &d);
    int flag = 0; //标记是否是闰年
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        flag = 1;
    int i = 0;
    for(i = 0; i < 12;i++)
    {
        if(i==2 && flag==1)
            days[i]++;
        if(d-days[i]>0)
            d = d - days[i];
        else break;
    }
    cout << i + 1 << endl;
    cout << d << endl;
    
    system("pause");
    return 0;
}
