#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//猜数字游戏
int main()
{
    int n, m, i;
    char arr[4];
    printf("Do you want to play a game with me?\n");
    scanf("%s", arr);
    if(arr[0]=='n'&&arr[1]=='o')
        return 0;
    printf("Please enter your number.\n");
    srand( (unsigned)time( NULL ) );
    m = rand() % 100 + 1;
    for (i = 1; i <= 100;i++)
    {
        scanf("%d", &n);
        if(n==m)
        {
            printf("bingo");
            break;
        }
        if(n<m)
            printf("too small\n");
        if(n>m)
            printf("too big\n");
    }
    //system("pause");
    return 0;
}