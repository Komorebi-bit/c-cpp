//小写字母转换成对应的大写字母
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch1,ch2;
    scanf("%c",&ch1);
    ch2=ch1-32;
    printf("ASCII of %c is %d",ch2,ch2);

    char a = 'a';
    printf("\n %c-%d \n", a, a); //可以打印出字符的ASCII编码十进制数

    system("pause");
    return 0;
}
