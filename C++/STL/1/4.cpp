#include <iostream>

using namespace std;

//模拟题 跳一跳
/*
未跳到方块中心+1分，第一跳跳到方块中心，或前一次未跳到方块中心但这次跳到方块中心+2，
否则此次得分比上一次得分多2分（即连续跳到中心，+2，+4，+6，+8）
1表示未跳到方块中心，2表示跳到方块中心，0表示未跳到方块上（即游戏结束）

样例输入：1 1 2 2 2 1 1 2 2 0
样例输出：22
*/

int main()
{
    int a[100] = {0};
    int i = 0;
    while(cin>>a[i],a[i++]!=0);

    i = 0;
    int score = 0, t = 0;
    while(a[i]!=0)
    {
        if(a[i]==1)
        {
            score += 1;
            i++;
        }
        else if(a[i] == 2)
        {
            score += 2;
            t = 2;
            while(a[++i] == 2)
            {
                t += 2;
                score += t;
            }
        }

    }
    cout << score << '\n';
    system("pause");
    return 0;
}
