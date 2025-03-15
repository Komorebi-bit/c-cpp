#include <stdio.h>
#include <stdlib.h>
//输入两个正整数m和n，求其最大公约数和最小公倍数
int main()
{
    int m, n;
    scanf("%d,%d", &m, &n);
    int a= m;
    int b = n;
    int r = a % b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    printf("%d,%d", b,(m*n/b));
    system("pause");
    return 0;
}