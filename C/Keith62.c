#include<stdio.h>
//输出1000以内的所有回文平方数
int huiwen(int i1);
int pingfang(int i2);
int main()
{
  int i,n,m;
  for(i=1;i<=1000;i++)
  {
      n=huiwen(i);
      m=pingfang(i);
      if(n==1&&m==1)
          printf("%d ",i);
  }
}
int huiwen(int i1)
{
    int a=0,b,c;
    for(b=i1;b>=1;b=b/10)
    {
        c=b%10;
        a=a*10+c;
    }
    if(a==i1)
        return 1;
    else
        return 0;
}
int pingfang(int i2)
{
    int x;
    for(x=1;x<=i2;x++)
    {
        if(x*x==i2)
        {
            break;
        }
    }
    if(x*x==i2)
        return 1;
    else
        return 0;
}


