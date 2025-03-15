#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    void f(int n,char a,char b,char c);
    f(n,'A','B','C');
    system("pause");
    return 0;
}
void f(int n,char a,char b,char c)
{
    if(1==n)
    {
        cout << a << "->" << c << endl;
        return;
    }
    f(n-1, a, c, b);
    cout << a << "->" << c << endl;
    f(n-1, b, a, c);
}