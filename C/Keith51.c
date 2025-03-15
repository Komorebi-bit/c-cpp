#include <stdio.h>
//求水仙花数
//一个 3 位数，它的每个数位上的数字的 3次幂之和等于它本身
//例如：1^3 + 5^3+ 3^3 = 153
int main()
{
    int i,x,y,t,s=0;
    for (i = 100; i <= 999;i++)
    {
        t= i;
        x = t/ 100;
        t = t % 100;
        y = t/ 10;
        t = t % 10;
        s = t * t * t + x * x* x + y* y * y;
        if (s == i)
            printf("%d ", i);
    }
    return 0;
}
