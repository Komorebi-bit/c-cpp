#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char str[20];
    int len,i,t=0;
    char a;
    gets(str);  //读入字符串（包括空格）
    scanf("%c", &a);
    len = strlen(str);
    for (i = 0; i <len ;i++)
    {
        if(str[i]==a)
        {
            printf("%d", i);
            t=1;
            break;
        }
    }
    if(!t)printf("-1");
    system("pause");
    return 0;
}
