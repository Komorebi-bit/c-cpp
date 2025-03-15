#include <stdio.h>
//矩阵中找最大值
int main()
{
    int m, n,i,j;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int t,m1,n1;
    t = a[0][0];
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < n;j++)
        {
            if(a[i][j]>t)
            {
                t = a[i][j];
                m1 = i;
                n1 = j;
            }
        }
    }
    printf("%d\n%d %d", t, m1, n1);
    return 0;
}
