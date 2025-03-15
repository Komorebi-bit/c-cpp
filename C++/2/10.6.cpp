#include <iostream>
#include <cstring>
#include <algorithm>        //sort()函数
#include <iomanip>
using namespace std;
int n;
struct student
{
    string xh,xm;
    int sx,yy,yw,pj,zcj;
    int pm;
};
bool cmp(student x,student y)
{
    if(x.zcj!=y.zcj)
    {
        return x.zcj>y.zcj;
    }
    else
    {
        return x.xh<y.xh;
    }
}
void show(student xs)
{
    cout<<setw(4)<<xs.pm<<setw(10)<<xs.xh<<setw(10)<<xs.xm<<setw(5)<<xs.sx<<setw(5)<<xs.yy<<setw(5)<<xs.yw<<endl;
}
int main()
{
    cin>>n;
    student xs[10];
    if(n>=10)
    {
        cout<<"Please input 1-9."<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            cin>>xs[i].xh>>xs[i].xm>>xs[i].sx>>xs[i].yy>>xs[i].yw;
        }
        for(int i=0;i<n;i++)
        {
            xs[i].zcj=xs[i].sx+xs[i].yy+xs[i].yw;
        }
        sort(xs,xs+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(xs[i].zcj!=xs[i-1].zcj)
            {
                xs[i].pm=i+1;
            }
            else
            {
                xs[i].pm=xs[i-1].pm;
            }
        }
        for(int i=0;i<n;i++)
        {
            show(xs[i]);
        }
    }
    system("pause");
    return 0;
}


