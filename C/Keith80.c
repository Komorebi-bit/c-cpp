#include<stdio.h>
#include<stdlib.h>
typedef struct date//(在不使用它的话，可有可无)
{
    int year;
    int month;
    int day;
} STU;
int main()
{
    STU s;
    int t=0,a=0;
    scanf("%d%d%d", &s.year, &s.month, &s.day);
    if((s.year%4==0&&s.year%100!=0)||s.year%400==0)
        a=29;
    else a=28;
    switch(s.month)
    {
    case 1:t=s.day;break;
    case 2:t=31+s.day;break;
    case 3:t=a+31+s.day;break;
    case 4:t=a+62+s.day;break;
    case 5:t=a+92+s.day;break;
    case 6:t=a+123+s.day;break;
    case 7:t=a+153+s.day;break;
    case 8:t=a+184+s.day;break;
    case 9:t=a+215+s.day;break;
    case 10:t=a+245+s.day;break;
    case 11:t=a+276+s.day;break;
    case 12:t=a+306+s.day;break;
    }
    printf("%d\n", t);
    system("pause");
    return 0;
}