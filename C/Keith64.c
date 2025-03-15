#include<stdio.h>
#include<stdlib.h>
float a,b;
void max_min(int n,float *p);
int main()
{
    int n,i;
    scanf("%d", &n);
    float *ptr = (float *)malloc(n * sizeof(float));
    for (i = 0; i < n;i++)
    {
        scanf("%f", (ptr+i));
    }
    max_min(n, ptr);
    printf("%.2f\n%.2f", a, b);
    free(ptr);
    return 0;
}
void max_min(int n,float *ptr)
{
    int i;
    a = *ptr;
    b = *ptr;
    for (i = 0; i < n;i++)
    {
        if ( a<= *(ptr+i))
        {
            a = *(ptr+i) ;
        }
        if (b>= *(ptr+i))
        {
            b = *(ptr+i);
        }
    }

}