#include<stdio.h>
#include<stdlib.h>
//删除数组中的下标为n的元素。
int main()
{
    int arr1[10];
    int i;
    for (i = 0; i < 10;i++)
    {
        scanf("%d", &arr1[i]);
    }
    int n;
    scanf("%d", &n);
    int arr2[9];
    for (i = 0; i <n;i++)
    {
        arr2[i] = arr1[i];
    }
    for (i = n; i <9;i++)
    {
        arr2[i] = arr1[i + 1];
    }
    for (i = 0; i < 9;i++)
    {
        printf("%-7d\n", arr2[i]);  //-左对齐， 7位
    }
    system("pause");
    return 0;
}