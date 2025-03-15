//输入正整数m,n，求它们的最大公约数和最小公倍数
//定义函数gcd(m, n)求最大公约数，函数lcm(m, n)求最小公倍数
//main函数负责读取正整数m,n，以及输出最后结果
#include<stdio.h>
int gcd(int m,int n)
{
    int i;
    if(m<=n)
        i = m;
    else
        i = n;
    while(m % i != 0 || n %i != 0)
        i--;
    return i;
}
int lcm(int m,int n)
{
    int i;
    if(m<=n)
        i = n;
    else
        i = m;
    while (i % m != 0 || i % n != 0)
        i++;
    return i;
}
/*
int gcd(int m,int n)
{
    int r;
    r = m % n;
    while(r!=0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}
int lcm(int m,int n)
{
    return (m * n) / gcd(m, n);
}
*/
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d %d",gcd(m,n),lcm(m,n));
    return 0;
}