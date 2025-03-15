#include <stdio.h>
//查找n个整数的最大值和最小值
int main()
{
    int num[11];
    int i,t,j,max,min;
    for(i=0;i<11;i++)
    {      
        scanf("%d",&t);
        if(t==-1)
            break;
        num[i]=t;
    }
    max=num[0];
    min=num[0];
    for(j=0;j<=i-1;j++)
    {
        if(max<num[j])
            max=num[j];
        if(min>num[j])
            min=num[j];
    }
    printf("%d %d",max,min);
    return 0;
}
