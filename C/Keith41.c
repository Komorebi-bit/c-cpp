//求1 ＋2! ＋3! ＋…… ＋20! 的和
#include <stdio.h>
int main()
{ 
    long long n=1,sum=0;
    int i;
    for(i=1;i<=20;i++)
    {
        n=n*i;
        sum=sum+n;
    }
    printf("%lld",sum);
    return 0;
}
