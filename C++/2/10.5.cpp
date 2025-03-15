#include <iostream>
using namespace std;

int main()
{
    int n,m,cnt=0;
    int a[30][30];
    int b[30][30];
    cin>>n;
    void input(int n, int [30][30]);
    input(n, a);
    cin>>m;
    input(m, b);
    bool f(int [30][30], int [30][30], int, int, int, int);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==b[1][1])
            {
                if(f(a,b,i,j,n,m))
                {
                    cnt++;
                    cout<<i<<','<<j<<endl;
                    break;
                }

            }
        }
    }
    if(cnt==0)
    {
        cout<<"-1"<<endl;
    }
    return 0;
}

void input(int nn,int arr[30][30])
{
    for(int i=1;i<=nn;i++)
    {
        for(int j=1;j<=nn;j++)
        {
            cin>>arr[i][j];
        }
    }
}

bool f(int a[30][30], int b[30][30], int i,int j,int n,int m)
{
    int x=j;
    for(int k=1;k<=m;k++)
    {
        for(int h=1;h<=m;h++)
        {
            if(a[i][j]!=b[k][h] || i>n || j>n)
            {
                return 0;
            }
            j++;
        }
        i++;
        j=x;

    }
    return 1;
}