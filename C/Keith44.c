#include <stdio.h>
//输出正整数m、n之间(m<n)的素数

//质数又称素数。
//一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做质数
//否则称为合数（规定1既不是质数也不是合数）

int main()
{
    int m, n, i, j,k;
    scanf("%d%d", &m, &n);
    for(i = m; i <= n; i++)
    {
        k = 0;
        for(j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                k=1;
                break;
            }

        }
        if(k == 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}

