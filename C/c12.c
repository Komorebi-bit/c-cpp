#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void f1(int**p,int n);
void f2(int **p1, int **p2, int **p3, int n);
int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    int **p1 = (int **)malloc(sizeof(int *) * n);
    for ( i = 0; i < n;i++)
    {
        p1[i] = (int *)malloc(sizeof(int) * n);
    }
    int **p2 = (int **)malloc(sizeof(int *) * n);
    for ( i = 0; i < n;i++)
    {
        p2[i] = (int *)malloc(sizeof(int) * n);
    }
    int **p3 = (int **)malloc(sizeof(int*) * n);
    for ( i = 0; i < n;i++)
    {
        p3[i] = (int *)malloc(sizeof(int) * n);
    }
    f1(p1,n),f1(p2,n);
    f2(p1, p2, p3,n);
    int j = 0;
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n;j++)
        {
            printf("%10d", p3[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n;i++)
    {
        free (p1[i]);
        free (p2[i]);
        free (p3[i]);
    }
    free (p1);
    free (p2);
    free (p3);
    system("pause");
    return 0;
}
void f1(int** p,int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n;j++)
        {
            scanf("%d", &(p[i][j]));
        }
    }
}
void f2(int**p1,int**p2,int**p3,int n)
{
    int i = 0, j = 0,k=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            p3[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                p3[i][j] += p1[i][k] * p2[k][j];
            }
        }
    }
}
