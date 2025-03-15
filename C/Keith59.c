#include<stdio.h>
//求最大公约数和最小公倍数函数
int gcd(int m,int n,int a)
{
    int i,y=0;
    if(m<=n)
        i = m;
    else
        i = n;
    for (; i >0;i--)
    {
        if (m % i == 0 &&n %i== 0)
            {
                a = i;
                y = 1;
            }
        if(y==1)break;
    }
    return a;
}
int lcm(int m,int n,int b)
{
    int j,k,x=0;
    for (j = 1; j <= n; j++)
    {
        for (k = 1; k <= m;k++)
        {
            if( m*j==n*k)
               {
                   b = m * j;
                   x = 1;
               }
            if(x==1)
                break;
        }
    }
    return b;
}
int main()
{
    int m, n,a=0,b=0;
    scanf("%d%d", &m, &n);
    a = gcd(m,n,a);
    b = lcm(m,n,b);
    printf("%d %d", a, b);
    return 0;
}

