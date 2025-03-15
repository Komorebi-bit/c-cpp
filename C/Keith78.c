#include <stdio.h>

typedef struct student
{
    char no[20];
    char name[50];
    char age[3];
    int score[6];
    int credit[6];
    int total;
} STU;

int main()
{
    STU s;
    s.total = 0;
    s.credit[0] = 4;
    s.credit[1] = 3;
    s.credit[2] = 4;
    s.credit[3] = 3;
    s.credit[4] = 3;
    s.credit[5] = 3;
    scanf("%s%s%s%d%d%d%d%d%d", s.no, s.name, s.age, &s.score[0], &s.score[1], &s.score[2], &s.score[3], &s.score[4], &s.score[5]);
    for (int i = 0; i < 6;i++)
    {
        if (s.score[i] > 60)
            s.total = s.total + s.credit[i];
    }    
    printf("%s %s %s\n%d", s.no, s.name, s.age,s.total);
    return 0;
}