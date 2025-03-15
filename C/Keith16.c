#include <stdio.h>
#include <stdlib.h>
//指针练习
int main()
{
    int arr[10] = {0};
    int i;
    int *p = arr;
    for (i = 0; i < 10;i++)
    {
        *p = i;
        p++; //p=p+1也可 下一个数组元素地址
    }
    for(i = 0; i < 10;i++)
    {
        printf("%d\n", arr[i]);
    }
    system("pause");
    return 0;
}