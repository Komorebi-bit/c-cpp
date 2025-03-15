#include <iostream>
#include <map>
using namespace std;
int a[20];
map<int,int>v;
int main()
{
    int cnt=18;
    for(int i=0;i<18;i++)
    {
        cin>>a[i];
        v[a[i]]++;
    }
    for(map<int,int>::iterator it=v.begin();it!=v.end();it++)
    {
        if(it->second==2 && it->first!=0)
        {
            cnt-=2;
        }
        if(it->second==4 && it->first!=0)
        {
            cnt-=4;
        }
        if(it->second==3)
        {
            cnt-=2;
        }
    }
    cout<<cnt<<endl;
    system("pause");
    return 0;
}