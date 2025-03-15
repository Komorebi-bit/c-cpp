//实训练习2.3-4-1 输出１ ~１００ 的随机数
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
    srand((unsigned)time(NULL));
    printf("%d\n",rand()%100);
    return 0;
}

