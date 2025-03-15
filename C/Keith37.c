#include<stdio.h>
//计算天数
int main()
{
    int year,month,day,a,b,t;
    scanf("%d/%d/%d",&year,&month,&day);
    if(year%4==0&&year%100!=0||year%400==0)//闰年 被400整除 或者 被4整除但不能被100整除
        a=29;
    else a=28;
    switch(month)
    {
    case 1:t=day;break;
    case 2:t=31+day;break;
    case 3:t=a+31+day;break;
    case 4:t=a+62+day;break;
    case 5:t=a+92+day;break;
    case 6:t=a+123+day;break;
    case 7:t=a+153+day;break;
    case 8:t=a+184+day;break;
    case 9:t=a+215+day;break;
    case 10:t=a+245+day;break;
    case 11:t=a+276+day;break;
    case 12:t=a+306+day;break;
    }
    printf("%d",t);
    return 0;
}
