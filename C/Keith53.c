#include <stdio.h>
//数制转换
int main()
{
    char num[] = "0123456789ABCDEF";//数字字符数组
    int mod[100];
    int n, d, i=0;
    scanf("%d%d", &n, &d);
    while(n!=0)
    {
        mod[i++] = n % d;
        n = n / d;
    }
    while(i>0)
        printf("%c", num[mod[--i]]);
    return 0;
}
