#include<stdio.h>
#include<string.h>
int main()
{
    char str[50],a[50];
    char *p, *q;
    q=a;
    gets(str);
    for(p=str;*p!='\0';p++)
    {
        if(*p<'A'||*p>'Z')
        {
            *q++ = *p; //*(q++) 先取指针 p 所指向的值，然后将指针 p 自增1; *q=*p; q++（下一个地址）;
        }
    }
    printf("%s",a);
    return 0;
}

