#include<iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cin >> n;
    for (int i = 1; i < n;i++)
    {
        if(n%i)
            continue;
        else
            sum += i;
    }
    if(sum<n)
        cout << "Deficit"<<endl;
    else if(sum==n)
        cout << "Perfect" << endl;
    else
        cout << "Surplus" << endl;
    system("pause");
    return 0;
}