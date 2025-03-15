#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Fibonacci(int);
    cout << Fibonacci(n)<< endl;
    system("pause");
    return 0;
}
int Fibonacci(int n)
{
    if(2==n||1==n)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}