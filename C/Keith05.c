#include <stdio.h>
int main()
{
    int n,m,i,j,t=0;
    scanf("%d",&n);
    for(i=1;i<8;i++)
    {
        for(j=i+1;j<9;j++)
        {
           m=(i*10+j)*(j*10+i);
           if(m==n)
                {
                    printf("%d=%d*%d",n,i*10+j,j*10+i);
                    t++;
                }
        }
    }
    if(t==0)
        printf("No Answer");
    return 0;
}

