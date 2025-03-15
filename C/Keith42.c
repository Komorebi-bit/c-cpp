#include<stdio.h>
//求一个正整数的所有因数
int main()
{
    int i=1,n;
    scanf("%d",&n);
    do
    {
       if(n%i==0)
        printf("%d ",i);
       i++;
    }while(i<=n);
    return 0;
}

