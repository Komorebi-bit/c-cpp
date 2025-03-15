#include<stdio.h>
#include<stdlib.h>
void revserse(int *arr, int n);
int main()
{
    int n,i;
    if(scanf("%d", &n));
    int *p = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n;i++)
    {
        if(scanf("%d", p + i));
    }
    revserse(p, n);
    free(p);
    return 0;
}
void revserse(int *arr, int n)
{
    int i;
    for (i = 0; i < n/2;i++)
    {
        int temp = *(arr+i);
        *(arr + i) = *(arr + (n - i - 1));
        *(arr + (n - i - 1)) = temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}