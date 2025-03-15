#include<iostream>
using namespace std;

string judge(int, int, int);
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << judge(a, b, c) << endl;
    system("pause");
    return 0;
}
string judge(int a,int b,int c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
        return "It is not a triangle";
    else if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
        return "It is a right triangle";
    else
        return "It is not a right triangle";
}