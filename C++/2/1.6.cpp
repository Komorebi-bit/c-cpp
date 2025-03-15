#include<iostream>
#include<cmath>
using namespace std;

void f();

int main()
{
    f();
    //system("pause");
    return 0;
}
void f()
{
    int i;
    for (i = 1000; i < 10000;i++)
    {
        int n = i;
        int sum=0;
        while (n)
        {
            sum += pow((n % 10), 4);
            n /= 10;
        }
        if (i == sum)
        {
            cout << i<<endl;
        }
    }
}