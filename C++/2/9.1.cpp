#include<iostream>
using namespace std;
//递归实现n的阶乘
int main()
{
    int n = 0;
    cin >> n;
    int factorial(int);
    cout << factorial(n) << endl;
    system("pause");
    return 0;
}
int factorial(int n)
{
    if(1==n)
        return 1;
    return n*factorial(n - 1);
}