#include <iostream>
#include <cstring>

#define MOD 10000

using namespace std;

//矩阵乘法求斐波那契数列

void mul(int a[][2], int b[][2]);
int fib(int n);

int main()
{
    int n;
    while(cin>>n, n!=-1) //逗号表达式，返回值取决于最右侧的值
        cout << fib(n) << endl;
    system("pause");
    return 0;
}

int fib(int n)
{
    int a[2][2] = {0, 1, 0, 0}; //{{0, 1}, {0, 0}}
    int f[2][2] = {0, 1, 1, 1};
    while(n)  //快速幂
    {
        if(n&1) //奇数
            mul(a, f);
        mul(f, f);
        n >>= 1; //左移一位并赋值
    }
    return a[0][0];
}

void mul(int a[][2], int b[][2])  //矩阵乘法
{
    int c[2][2] = {0};
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    for (int k = 0; k < 2; k++)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    memcpy(a, c, sizeof c);//sizeof(c) or 4*4
}
