#include <stdio.h>
//输入两个分数，对两个分数相加求和，要求和为最简分式。(两个分数为正数）
int main(void)
{
    int m, n, p, q;
    scanf("%d/%d,%d/%d", &m, &n, &p, &q);
    int i = m * q + n * p;
    int j = n * q;
    int a = i;
    int b = j;
    int r = a % b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    if((i/b)%(j/b)==0) //整数
        printf("%d", (i / b) / (j / b));
    else //分数
        printf("%d/%d", i / b, j / b);
    return 0;
}