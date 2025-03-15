//深度搜索
#include<iostream>
using namespace std;
int s[100];     //拆分结果保存在这个数组里
int top;        //记录个数
int total, n;   //累加数和所求数
int k;
void dfs(int index)
{
    int i;
    if (total == n)     //满足打印出来
    {
        printf("%d=", n);
        for (i = 0; i<top-1; i++)
            printf("%d+", s[i]);
        k++;
        if (k == 4||top==1) //四个或最后一个了一换行，换行时的特殊讨论
        {
            k = 0;
            printf("%d\n", s[top - 1]);
        }
        else
            printf("%d;", s[top - 1]);
        return;
    }
    if (total>n)          //累加大于所需跳出
        return;
    for (i = index; i <=n; i++)
    {
        total += i;
        s[top++] = i;  //将每次加的数保存在数组里
        dfs(i);
        total -= i;
        s[--top];      //回退
    }
}
int  main()
{
    //cin >> n;
    while (cin >> n)
    {
        k = 0;
        top = 0;
        total = 0;
        dfs(1);
    }
    //system("pause");
    return 0;
}
