#include<stdio.h>
#include<malloc.h>
//顺时针旋转打印
void cube(int n, int **p);
int main()
{
    int n;
    scanf("%d", &n);
    int **p = (int **)malloc(sizeof(int *) * n);
    int i,j;
    for (i = 0; i < n;i++)
    {
        p[i] = (int *)malloc(sizeof(int) * n);
    }
    cube(n, p);
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n;j++)
        {
            printf("%5d", p[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n;i++)
    {
        free (p[i]);
    }
    free (p);
    //system("pause");
    return 0;
}
void cube(int n, int **p)
{
    int x = 0, y = 0, k = 1;
    int i, j;
    while(k<=n*n)
    {
        i = x;
        j = y;
        while(j<n-x-1)
            p[i][j++] = k++;
        while(i<n-y-1)
            p[i++][j] = k++;
        while(j>x)
            p[i][j--] = k++;
        while(i>y)
            p[i--][j] = k++;
        x++;
        y++;
        if(x==n-x-1&&y==n-y-1)
            p[x][y] = k++;
    }
}