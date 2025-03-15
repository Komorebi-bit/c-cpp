//厘米换算英尺英寸
#include<stdio.h>
int main()
{
  int x,a,b;
  scanf("%d",&x);
  a=x/30.48;
  b=(x/30.4800-a)*12+1;
  printf("%d %d",a,b);
  return 0;
}

