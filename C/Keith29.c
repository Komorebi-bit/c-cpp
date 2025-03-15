//出租车计价
#include<stdio.h>
int main()
{
    double s,f;
    int t;
    scanf("%lf%d",&s,&t);
    if(s<=3)
        f=10;
    else if(s<=10)
        f=10+(s-3)*2;
    else f=24+(s-10)*3;
    f=f+t/5*2;
    printf("%.0f",f);
    return 0;
}

