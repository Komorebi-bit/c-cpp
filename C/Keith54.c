#include <stdio.h>
//字符串排序——冒泡法排序,H2e3L*Lo,Wor#Ld.
int main()
{
    char str[20];
    int i,j,ch,len;
    gets(str);
    len=strlen(str);
    for(i=1;i<len;i++)
        for(j=0;j<len-i;j++)
            if(str[j]>str[j+1])
            {
                ch=str[j];
                str[j]=str[j+1];
                str[j+1]=ch;
            }
     puts(str);
     return 0;

}

