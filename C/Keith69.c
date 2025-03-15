#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//设计一个函数int stoi(char* str),将数字字符串str转换为一个整数.
//main读取一个由数字字符构成的字符串放入数组,
//然后调用stoi函数得到转换后的整数并输出.
int stoi(char *str);
int main()
{
    char arr[100]={0};
    gets(arr);
    printf("%d\n",stoi(arr));
    return 0;
}
int stoi(char *str)
{
    int i,len = strlen(str);
    if(len == 0)
        return 0;
    int flag = 1;
    int sum = 0;
    if(str[0] == '-')
        flag = -1;
    for(i=0;i<len;i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            sum = sum*10 + str[i] - '0';
        }
        else
        {
            if(i != 0)
                return 0;
        }
    }
    return flag*sum;
}