/*
编写程序求分数序列 2/1,3/2,5/3,8/5,13/8,21/13……的前n项之和。
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double sum=0;
    int n, i, a=2, b=1, temp;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        sum = sum + (double)a/b;
        temp = a + b;
        b = a;
        a = temp;
    }
    printf("%.3f\n", sum);
    system("pause");
    return 0;
}