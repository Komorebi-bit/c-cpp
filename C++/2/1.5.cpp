#include<iostream>
using namespace std;

int sum(int);   //函数声明

int main()
{
    int n,a;
    cin >> n;
    while(n--)
    {
        cin >> a;
        cout << sum(a)<<endl;   //传入实参a
    }
    //system("pause");
    return 0;
}
int sum(int i)      //新开辟一块空间i(形参),其值等于a
{
    int sumv = 0;
    while(i)
    {
        sumv += i % 10;
        i /= 10;
    }
    return sumv;    //函数返回值与函数类型一致,且只能返回一个
}