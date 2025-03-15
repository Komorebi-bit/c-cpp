//求两个整数相除的商和余数
#include<stdio.h>
int main()
{
  int dividend ,divisor,quotient,remainder;
  printf("");
  scanf("%d",&dividend);
  printf("");
  scanf("%d",&divisor);
  quotient=dividend/divisor;
  remainder=dividend%divisor;
  printf("quotient=%d\n",quotient);
  printf("remainder=%d",remainder);
  return 0;
}

