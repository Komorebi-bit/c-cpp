#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int factor(int);
    int sum_n=factor(n);
    int sum_m=factor(m);
    if( sum_n == m && n == sum_m )
        cout << 1 << endl;
    else
        cout << 0 << endl;
    system("pause");
    return 0;
}
int factor(int x)
{
    int sum=0;
    cout << x << ",";
    for (int i = x - 1; i >= 1;i--)
    {
        if(x%i==0)
        {
            sum +=i;
            if(i!=1)
                cout << i << "+";
            else
                cout << i << "="<<sum<<endl;
        }
    }
    return sum;
}