#include <stdio.h>
//从m个元素中任取n个元素的组合数
int m;
int factorial(int n)
{
    int x=1,y=1,i,j;
    j=m;
    for(i=0;i<n;i++)
    {
        x=x*j;
        j--;
    }
    for(i=1;i<=n;i++)
    {
        y=y*i;
    }
    return x/y;
}
int main()
{
    int n;
    scanf("%d%d",&m,&n);
    printf("%d",factorial(n));
    return 0;
}

