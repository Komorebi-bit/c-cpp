#include <stdio.h>
#include <string.h>
//查找字符
int main()
{
    char str[20];
    int len,i,t=0;
    char a;
    gets(str);
    scanf("%c", &a);
    len = strlen(str);
    for (i = 0; i <len ;i++)
    {
        if(str[i]==a)
        {
            printf("%d", i);
            t++;
            break;
        }   
    }
    if(t==0)printf("-1");
    return 0;
}
