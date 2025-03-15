//给定一个正整数 Ｎ，如果 Ｎ 是另一个正整数的平方，则 Ｎ 为平方数。
//定义一个函数isSquare，判断一个正整数Ｎ是否为平方数。
//main函数负责读取整数N和输出最后结果。
#include <stdio.h>
int isSquare(int n)
{
    int m=0;
    for (int i = 1; i <= n;i++)
    {
        if(i*i==n)
        {
            m=1;
            break;
        }
    }
    return m;
}
int main(void)
{
    int n,m;
    scanf("%d", &n);
    m = isSquare(n);
    if(m==1)
        printf("yes");
    else
        printf("no");
    return 0;
}