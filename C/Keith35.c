//练习3-2 打印成绩等级
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int z;
    scanf("%d",&z);
    z=z/10;
    switch(z)
    {
        case 10: //没有break接着往下执行
        case 9:printf("A");break;
        case 8:printf("B");break;
        case 7:printf("C");break;
        case 6:printf("D");break;
        case 5:;
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            printf("E");break;
            break;
    }
    system("pause");
    return 0;
}

