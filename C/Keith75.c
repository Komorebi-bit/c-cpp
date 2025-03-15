#include<stdio.h>
#include<stdlib.h>
//输入n个整数（从小到大）存入数组，然后使用折半查找指定的整数m,
//如果找到m，输出m在数组中的下标；如果没有找到，输出“not found”.
//定义一个函数实现查找过程,
//函数原型：int binarySearch(int nums[], int len, int item);
//其中参数nums指向存放整数的数组，len是整数个数，item是要查找的整数，如果成功返回下标，否则返回-1.

//非递归

int binarySearch(int nums[], int len, int item);
int main()
{
    int n;
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n;i++)
    {
        scanf("%d", ptr + i);
    }
    int item;
    scanf("%d", &item);
    if(binarySearch(ptr, n, item)==-1)
        printf("not found");
    else
        printf("%d", binarySearch(ptr, n, item));
    return 0;
}
int binarySearch(int nums[], int len, int item)
{

	int left=0,right=len-1,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(item==nums[mid])
            return mid;
		else if(item<nums[mid])
			right=mid-1;
		else left=mid+1;
	}
    return -1;
}
