#include <stdio.h>
#include<stdlib.h>
//输入一个整数，判断这个数中出现了哪些数字，各出现了几次。
int main()
{
    long long num = 0;
    int arr[10] = {0}; //初始化数组，数据元素均为0
    scanf("%lld", &num);
    if(num<0)
        num = -num;
    do
    {
        arr[num % 10] += 1;
        num = num / 10;
    } while (num);

    for (int index = 0; index < 10; index++)
    {
        if (arr[index])
        {
            printf("%d:%d\n", index, arr[index]);
        }
    }
    system("pause");
    return 0;
}
