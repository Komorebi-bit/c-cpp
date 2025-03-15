#include <stdio.h>
//输入一个非负整数，求各个位上数字之和
int main()
{ 
       int n, digit, sum=0;
       scanf("%d",&n);
       while (n > 0)
       {
            digit =n % 10;
            n = n / 10;
            sum = sum + digit;
       }
       printf("%d", sum);
       return 0;
}
