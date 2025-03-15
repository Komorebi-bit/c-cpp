#include <stdio.h>
#include <math.h>
typedef struct nums
{
    double x;
    double y;
    double z;
} STU;
int main()
{
    STU s[2];
    int i;
    for (i = 0; i < 2;i++)
    {
        scanf("%lf%lf%lf", &s[i].x, &s[i].y, &s[i].z);
        //printf("%lf %lf %lf", s[i].x, s[i].y, s[i].z);
    }
    double L = 0;
    L = sqrt((s[0].x - s[1].x) * (s[0].x - s[1].x)+(s[0].y - s[1].y) * (s[0].y - s[1].y) +  (s[0].z - s[1].z) * (s[0].z - s[1].z) );
    printf("%.2lf", L);
    return 0;
}