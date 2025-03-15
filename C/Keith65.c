#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *ptr = (int *)malloc(n * sizeof(int));
    int i, sum = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    float meanvalue=0,stadeviation=0,deviation=0;
    for(i=0;i<n;i++)
    {
        sum=sum+*(ptr+i);
        meanvalue=sum/(n*1.0);
    }
    for(i=0;i<n;i++)
    {
        deviation=deviation+(*(ptr+i)-meanvalue)*(*(ptr+i)-meanvalue);
        stadeviation=sqrt(deviation*1.0/n);  //sqrt平方根
    }
    printf("%.2f %.2f",meanvalue,stadeviation);
    return 0;
}