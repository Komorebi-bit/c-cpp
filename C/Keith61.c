#include <stdio.h>
//判断平方数函数
int isSquare(int n)
{
    int m=0;
    for (int i = 1; i <= n;i++)
    {
        if(i*i==n)
            {
                m=1;
                break;
            }
    }
    return m;
}
int main(void)
{
    int n,m;
    scanf("%d", &n);
    m = isSquare(n);
    if(m==1)
        printf("yes");
    else
        printf("no");
    return 0;
}

