#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//字符串的连接
int main()
{
    int i,j;
    char s1[20],s2[20];
    gets(s1);
    gets(s2);
    char s3[strlen(s1)-1+strlen(s2)+1];
    for(i=0;i<=strlen(s1)-1;)
    {
        s3[i]=s1[i];
        i++;
    }
    for(j=0;j<strlen(s2)+1;j++,i++)
    {
        s3[i]=s2[j];
    }
    puts(s3);

    // char s[2];
    // gets(s); //越界可以正常运行
    // puts(s);
    // printf("%c", s[1]);

    system("pause");
    return 0;
}
