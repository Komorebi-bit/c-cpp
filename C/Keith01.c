//编程实现求三个整数的平均值，其中定义一个函数avg, 求三个整型数的均值, 要求有返回值。
//main函数负责读取数据和输出结果。
#include <stdio.h>
float avg(int x,int y,int z,float t)
{
    t = (x + y + z) / 3.0;
    return t;
}
int main()
{
    int x, y, z;
    float t=0;
    scanf("%d%d%d", &x, &y, &z);
    t=avg(x, y, z, t);
    printf("%.2f", t);
    system("pause");
    return 0;
}