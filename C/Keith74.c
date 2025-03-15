#include <stdio.h>
#include <stdlib.h>
long long f(int n);
int main()
{
    int n;
    if(scanf("%d", &n))
    {
        printf("%lld\n", f(n));
    }
    else
        printf("False");
    system("pause");
    return 0;
}
long long f(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    // return f(n - 1) + f(n - 2);
    long long a=1, b=1, c;
    for (int i = 3; i <= n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}