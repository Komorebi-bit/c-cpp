#include<stdio.h>
#include<string.h>
//使用全局变量求最大公约数和最小公倍数
void f(int m,int n)
{
    int a[2];
    int i,t,y=0;
    if(m<=n)
        i = m;
    else
        i = n;
    for (; i >0;i--)
    {
        if (m % i == 0 &&n %i== 0)
            {
                a[0]=i;
                y = 1;
            }
        if(y==1)break;
    }
    int j,k,x=0;
    for (j = 1; j <= n; j++)
    {
        for (k = 1; k <= m;k++)
        {
            if( m*j==n*k)
                {
                    a[1]= m * j;
                    x = 1;
                }
            if(x==1)
                break;
        }
    }
    //return a[2];
    for (t = 0; t < 2;t++)
    {
        printf("%d ", a[t]);
    }
}
int main()
{
    int m, n;
    //int b[2]={0};
    scanf("%d%d", &m, &n);
    //b[2]=f(m,n);
    //for (t = 0; t < 2;t++)
    //{
    //   printf("%d ", b[t]);
    //}
    f(m, n);
    return 0;
}

