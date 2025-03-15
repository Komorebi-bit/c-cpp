#include<stdio.h>
#include<malloc.h>
void magic(int n, int **p);
int main()
{
    int n,i,j;
    scanf("%d", &n);
    int **p = (int **)malloc(sizeof(int *) * (n+1));
    for (i = 0; i < n+1; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * (n+1));
    }
    magic(n, p);
    for (i = 1; i <= n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            printf("%4d", p[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n+1;i++)
    {
        free(p[i]);
    }
    free(p);
    system("pause");
    return 0;
}
void magic(int n, int **p)
{
    int k = 1;
    int i=1, j=(n + 1) / 2;
    for (k = 1; k <= n * n;k++)
    {
        p[i][j] = k;
        if(k%n==0)
            i++;
        else
        {
            i--;
            if(i<1)
                i = n;
            j++;
            if(j>n)
                j = 1;
        }

    }
}