#include<stdio.h>
//求ｓ= ｍ+ ｍｍ + ｍｍｍ +…… ＋ ｍｍ……ｍ的值
int main()
{
    int m,n,i,t,sum=0;
    scanf("%d %d",&m,&n);
    printf("%d",m);
    sum=m;
    t=m;
    for(i=1;i<n;i++)
    {
       t=t*10+m;
       printf("+%d",t);
       sum=sum+t;
    }
    printf("=%d",sum);
    return 0;
}

