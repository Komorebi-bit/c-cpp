#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n, i,j, flag=0;
    scanf("%d", &n);
    int a[n], result[n];

    for (i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n;i++)
    {
        flag = 0;
        if(a[i]==0 ||a[i] ==1)
        {
            result[i] = 0;
            continue;
        }
        if (a[i] == 2) {
            result[i]=1;
            continue;
        }
        for (j = 2; j <= a[i]/2; j++) {
            if (a[i] % j == 0) {
                result[i] = 0;
                flag = 1;
            }
        }
        if(flag == 0)
        {
             result[i] = 1;
        }

    }

    for (i = 0; i < n;i++)
    {
        if(result[i] == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }
    //system("pause");
}
