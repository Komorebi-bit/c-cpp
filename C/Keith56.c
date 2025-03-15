#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//删除字符
int main()
{
    int len,i,j=0;
    char str[20]={0},str1[20]={0};
    gets(str);
    len = strlen(str);
    for (i = 0; i < len;i++)
    {
        if((65<=str[i]&&str[i]<=90)||(97<=str[i]&&str[i]<=122))
        {
            str1[j] = str[i];
            j++;
        }
    }
    puts(str1);
    system("pause");
    return 0;
}

