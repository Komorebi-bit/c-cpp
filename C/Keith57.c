#include <stdio.h>
//两个正整数之间能被５整除， 但不能被3整除的数
int f(m,n)
{
    int i;
    for(i=m;i<=n;i++)
    {
        if(i%5==0&i%3!=0)
            printf("%d ",i);
    }
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    f(m,n);
    return 0;
}


