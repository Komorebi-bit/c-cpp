#include <stdio.h>
//求均值函数
float avg(int x,int y,int z,float t)
{
    t = (x + y + z) / 3.0;
    return t;
}
int main(void)
{
    int x, y, z;
    float t=0;
    scanf("%d%d%d", &x, &y, &z);
    t=avg(x, y, z, t);
    printf("%.2f", t);
    return 0;
}

