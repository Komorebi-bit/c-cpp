#include <stdio.h>
//判断一个数是否为回文数
int main()
{
    int ON,RN=0,n,t;
    scanf("%d",&n);
    ON=n;
    while(n>0)
    {
        t=n%10;
        n=n/10;
        RN=RN*10+t;
    }
    if(ON==RN)printf("yes");
    else printf("no");
    return 0;
}

