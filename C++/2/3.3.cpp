#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int gcd(int, int);
    int lcm(int ,int);
    switch(n)
    {
        case 1:
            cout << gcd(a, b) << endl;
            break;
        case 2:
            cout << lcm(a, b) << endl;
            break;
        default:
            cout << "falth";
    }
    system("pause");
    return 0;
}
int gcd(int a,int b)
{
    int n;
    for (int i = 1; i < max(a, b);i++)
    {
        if(a%i==0&&b%i==0)
            n = i;
    }
    return n;
}
int lcm(int a,int b)
{
    return a * b / gcd(a, b);
}