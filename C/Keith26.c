//实训2.3-4 输出0到1之间的随机数
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(void)
{
    srand((unsigned)time(NULL));
    printf("%5.2f\n",rand()/32768.0);
    return 0;
}

