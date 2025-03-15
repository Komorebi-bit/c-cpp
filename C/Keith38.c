#include <stdio.h>
//multiply,	求阶乘
int main()
{
    int i=1,n;
    long long mul=1;
    scanf("%d",&n);
    while(i<=n)
    {
        mul=mul*i;
        i++;
    }
    printf("%lld",mul);
    return 0;
}

