#include<stdio.h>
#include<stdlib.h>

void sort(int *nums, int n);

int main(void)
{
    int n, i;
    if(scanf("%d", &n));
    int *p = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n;i++)
    {
        if(scanf("%d", p + i));
    }
    sort(p, n);
    for (i = 0; i < n;i++)
    {
        printf("%d ", *(p + i));
    }
    free(p);
    return 0;
}
void sort(int *nums, int n)
{
    int i,j;
    for (i = 1; i < n;i++)
    {
        for (j = 0; j < n - i;j++)
        {
            if(*(nums+j)>*(nums+j+1))
            {
                int temp = *(nums + j);
                *(nums + j) = *(nums + j + 1);
                *(nums + j + 1) = temp;
            }
        }
    }
}