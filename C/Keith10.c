//求组合数
#include<stdio.h>
int m;
int factorial(int n)
{
    int i,a=m;
    int x= 1, y = 1;
    for (i = 0; i <n;i++)
    {
        x = x * a;
        a--;
    }
    for (i = 1; i <= n;i++)
    {
        y = y* i;
    } 
    return   x / y;
}
int main()
{
    int n;
    scanf("%d%d", &m, &n);
    printf("%d", factorial(n));
    return 0;
}