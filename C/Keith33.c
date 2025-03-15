#include<stdio.h>
//简单的加减乘除计算器
int main()
{
    double x,y,z;
    int t;
    scanf("%lf%c%lf",&x,&t,&y);
    if(t=='+')
      z=x+y;
    if(t=='-')
      z=x-y;
    if(t=='*')
      z=x*y;
    if(t=='/')
      z=x/y;
    printf("%.2f",z);
    return 0;
}


