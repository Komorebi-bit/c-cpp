#include <stdio.h>
//矩阵转置
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    int b[n][n];
    int i, j;
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n;j++)
        {
            scanf("%d", &a[i][j]);
            b[j][i] = a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < n-1)
                 printf("%d ", b[i][j]);
             else
                printf("%d\n", b[i][j]);
         }
    }
    return 0;
}
