//判断素数（非函数）
#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<n;i++)
        if(n%i==0)break;
    if(i<n)
        printf("0");
    else printf("1");
    return 0;
}

