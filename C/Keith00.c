#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

int main(void)
{
    // char c;
    // scanf("%c", &c);
    char a[15];
    // gets(a);
    // printf("%c", c);
    fgets(a, sizeof(a), stdin);
    puts(a);
    printf("Hello world! \n");
    system("pause");
    return 0;
}

/*
    C语言 动态开辟二维数组
    int *p = (int *)malloc(sizeof(int) * n);        //动态申请一维数组

    int **q = (int **)malloc(sizeof(int *) * n);    //二维地址
    for (int i = 0; i < n;i++)
    {
        q[i] = (int *)malloc(sizeof(int) * n);
        free (*q[i]);
    }
    free (q);
    默认为十进制;
    0 八进制数;
    0x 十六进制数;
    0b 二进制数;
'5' - '0' = 5;
5 + '0'= '5'
#define PI 3.1415926
标志: - 输出结果左对齐(默认右对齐)
      + 有符号数转换后带正负号
      0 前置补零

字符串函数<string.h>
    strcpy(s1,s2):  复制字符串s2到字符串s1
    strcat(s1,s2):  连接字符串s2到字符串s1的末尾
    strlen(s1):     返回字符串s1的长度
    strcmp(s1,s2):  s1==s2  返回值等于零
                    s1<s2   返回值小于零
                    s1>s2   返回值大于零
int len=sizeof(数组名)/sizeof(数组名[0])；

字符，字符串的输入输出：
c = getchar() 读取一个字符（包括空格、换行符），返回值为该字符
scanf("%c",&c) 读取一个字符（包括空格、换行符）
putchar(c) 不会自动换行
printf("%c",c) 不会自动换行

scanf("%99s", str) 99: 最多读取99个字符，遇到空格、制表符\t或换行符\n会停止读取
gets(str) 可以读取空格，遇到换行符停止读取
printf("%s\n", str);
puts() 会自动换行

fgets(str, sizeof(str), stdin); 包括换行符，空格，
                                如果输入包含换行符，你可能需要手动去除它。
                                可以使用 strcspn() 来查找并去除换行符：
                                str[strcspn(str, "\n")] = '\0';  // 去除换行符


printf("%p\n",&arr[0])打印地址；
在指针变量中存储的地址
   printf("p 变量存储的地址: %p\n", p );
   使用指针访问值
   printf("*p 变量的值: %d\n", *p );
存放指针的数组称为指针数组，指针数组的一般定义形式：
                    类型名 *数组名[常量表达式]
返回指针值的函数称为指针函数，一般定义形式：
                    类型名 *函数名（参数列表）
                    {
                        …
                    }
强制转化:
    float a = 3.5;
    int b = (int)a;
    printf("%d\n", b);
    int c = 3;
    float d = (float)c;
    printf("%.3f", d);
typedef struct node //(node)在不用的情况下可有可无
{
    int a;
    float b;
    char arr[20];
    struct node *p;
} STU;

char arr[100] = {0}; //数组初始化
*/