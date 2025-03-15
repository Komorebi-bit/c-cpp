#include<stdio.h>
/*给定N个学生的基本信息，包括:学号（由5个数字组成的字符串)
                          姓名（长度小于10的不包含空白字符的非空字符串)
                          和3门课程的成绩（[0,100]区间内的整数)
要求输出总分最高学生的姓名、学号和总分。*/
typedef struct student
{
    char no[6];
    char name[10];
    int score[3];
    int total;
}STU;
int main()
{
    int n=0,i=0,max=0;
    scanf("%d",&n);
    STU s[n];
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d%d%d", s[i].no, s[i].name, &s[i].score[0], &s[i].score[1], &s[i].score[2]);
        s[i].total=s[i].score[0]+s[i].score[1]+s[i].score[2];
    }
    for(i=0;i<n;i++)
    {
        if(s[i].total>s[max].total)
            max=i;
    }
    printf("%s %s %d", s[max].name, s[max].no, s[max].total);
    return 0;
}
