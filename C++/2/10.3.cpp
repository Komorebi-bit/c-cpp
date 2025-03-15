#include <iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cin>>n;
    int add(int x);
    for(int i=1;i<=n;i++)
    {
        sum+=add(i);
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
int add(int x)
{
    int y=0;
    for(int i=1;i<=x;i++)
    {
        y+=i;
    }
    return y;
}


