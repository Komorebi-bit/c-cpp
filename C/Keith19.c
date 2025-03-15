//根据半径求圆的面积
#include<stdio.h>
#define PI 3.14
int main()
{
    float S=0,R=0;
    scanf("%f",&R);
    S=PI*R*R;
    printf("S=%.2f",S);
    return 0;
}

