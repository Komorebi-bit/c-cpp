#include <iostream>
/* 数学 */
using namespace std;

long long fast_pow(int, long long); // 快速幂
int euler_phi(int); // 欧拉函数
int gcd(int, int);  // 最大公约数
int lcm(int, int);  // 最小公倍数

int main()
{
    int m = 15, n = 20;
    cout << euler_phi(n) << '\n';
    cout << gcd(m, n) << ' ' << lcm(m, n) << '\n';
    system("pause");
    return 0;
}

/*
质数，素数，合数
除了1和它自身外，不能被其他自然数整除的数叫做质数；否则称为合数
规定1既不是质数也不是合数
*/

/*
φ(n)表示1~n中 与 x互质的数的个数
求解欧拉函数的值
计算公式 φ(x) = x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)…..(1-1/pn)，pi为质数
若m，n互质，φ(m*n) = φ(m)φ(n)
若n为质数，φ(n) = n-1
若n = p^k ,其中p为质数,那么φ(n) = p^k-p^(k-1) = p^(k-1)(p-1)
φ(1) = 1
通过找x的质因子来计算其欧拉函数
*/
int euler_phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

// 快速幂
long long fast_pow(int a, long long b)
{ // a是底数，b是指数
    long long ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

// 最大公约数 辗转相除法
int gcd(int m, int n)
{
    int r = m % n;
    while (r)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}
// 最小公倍数
int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}
