#include<stdio.h>
//查找数组中有无此数
int main()
{
    int a[10];
    int i;
    for (i = 0; i < 10; i++)      // scanf("%s",&a);
    {
        scanf("%d", &a[i]);
    }
    int n, temp = 0;
    scanf("%d", &n);
    for (i = 0; i < 10;i++)
    {
        if(n==a[i])
        {
            printf("yes,%d", i);
            temp = 1;
            break;
        }
    }
    if(!temp)
        printf("no");
    return 0;
}