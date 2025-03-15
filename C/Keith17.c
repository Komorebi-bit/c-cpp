#include <stdio.h>
//本题要求实现一个拆分实数的整数与小数部分的简单函数。在main里完成数据读取和结果输出。
//函数原型为
//void splitfloat( float x, int *intpart, float *fracpart );
//数据类型强制转化

void splitfloat(float x, int *intpart, float *fracpart);

int main()
{
    float x=0, fracpart=0;
    int intpart=0;
    if(scanf("%f", &x))
    //scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\nThe fractional part is %g\n", intpart,fracpart);
    return 0;
}
void splitfloat( float x, int *intpart, float *fracpart )
{
	*intpart=x;
	*fracpart=x-*intpart;
}