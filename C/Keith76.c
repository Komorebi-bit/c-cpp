#include<stdio.h>

//输入n个整数（从小到大）存入数组，然后使用折半查找指定的整数m,
//如果找到m，输出m在数组中的下标；如果没有找到，输出“not found”.
//定义一个函数实现查找过程,
//函数原型：int binarySearch(int nums[], int len, int item);
//其中参数nums指向存放整数的数组，len是整数个数，item是要查找的整数，如果成功返回下标，否则返回-1.

//递归

int binarySearch(int nums[], int item, int lower, int upper);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int item;
    scanf("%d", &item);
    int t;
    t = binarySearch(arr, item, 0, n - 1);
    if(t==-1)
        printf("not found");
    else
        printf("%d", t);
    return 0;
}
int binarySearch(int nums[],int item,int lower,int upper)
{
    int mid;
    if(lower>upper)
        return -1;
    mid = (lower + upper) / 2;
    if(nums[mid]==item)
        return mid;
    else if(nums[mid]<item)
        return binarySearch(nums, item, mid + 1, upper);
    else
        return binarySearch(nums, item, lower, mid - 1);
}