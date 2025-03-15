#include<stdio.h>
#include<string.h>
int stoi(char *str);
int main()
{
    char str[20] = {0};
    gets(str);
    int sum = stoi(str);
    printf("%d", sum);
    return 0;
}
int stoi(char *str)
{
    int i = 0,sum=0;
    int len = strlen(str);
    for (i = 0; i < len;i++)
    {
        int temp= str[i] - '0';
        sum = sum * 10 + temp;
    }
    return sum;
}