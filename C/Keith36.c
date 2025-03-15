//判断奇数/偶数
#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    b=a%2;
    switch(b)
    {
        case 0:printf("%d is even number.",a);break;
        case 1:printf("%d is odd number.",a);break;
    }
    return 0;
}

