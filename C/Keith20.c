//日期格式化,mm-dd-yyyy改为yyyy-mm-dd
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int a,b,c;
  scanf("%d-%d-%d",&a,&b,&c);
  printf("%d-%02d-%02d",c,a,b);// 02和.2在这里输出相同，都是两位数字，不够补0
  system("pause");
  return 0;
}

