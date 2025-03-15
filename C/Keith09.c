//若将 ｎ 的各位数字反向排列所得的自然数n1与 n相等, 则称n为回文数.例如,若 n=1234321,
//则称n为回文数.若 n=1234567, 则n不是回文数。
//如果一个数既是回文数，又是某个数的平方，则这样的数字称为平方回数，例如:121。
//编写两个函数，一个用于判断n是不是回文数，一个用于判断n是不是平方数，
//main函数调用这两个函数找出1000内的回文平方数。
#include <stdio.h>
#include <stdlib.h>
int f(int n)
{
    int sum = 0,x=0,t;
    int m = n;
    for (; m> 0;)
    {
        t= m % 10;
        m = m / 10;
        sum = sum*10 + t;
    }
    if (sum==n)
        x = 1;
    return x;
}
int g(int n)
{
    int i = 0, y = 0;
    for (i = 1; i <= n; i++)
    {
        if (i * i == n)
        {
            y = 1;
            break;
        }
    }
    return y;
}
int main()
{
    int n,x,y;
    for (n = 1; n <= 1000;n++)
    {
        x = f(n);
        y = g(n);
        if(x+y==2)
            printf("%d ", n);
    }
    system("pause");
    return 0;
}
