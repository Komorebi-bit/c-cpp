//找出3个实数中的最大值
#include<stdio.h>
#include<stdlib.h>
int main()
{
    double a,b,c,max;
    scanf("%lf%lf%lf",&a,&b,&c);
    // if(a>=b&&a>=c)
    //     max=a;
    // if(b>=a&&b>=c)
    //     max=b;
    // if(c>=a&&c>=b)
    //     max=c;
    if(a>b)
        max = a;
    else
        max = b;
    if(c>max)
        max = c;
    printf("max=%lf",max);
    system("pause");
    return 0;
}

