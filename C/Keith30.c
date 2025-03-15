#include<stdio.h>
//判断字母
int main()
{
    char a;
    scanf("%c",&a);
    if(a>=65&&a<=90)
      printf("yes");
    else if(a>=97&&a<=122)
      printf("yes");
    else printf("no");
    return 0;
}
