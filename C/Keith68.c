#include"stdio.h"
void value(int a,int b,int *ps,int *p);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int s,p;
    value(a,b,&s,&p);
    printf("%d %d",s,p);
    return 0;
}
void value(int a,int b,int *ps,int *p)
{
    *ps=a+b;
    *p=a*b;
}