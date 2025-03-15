#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *p = new int[20001];
    for (int i = n; i <= m;i++)
    {
        p[i] = 0;
        for (int j = 1; j < i;j++)
        {
            if(i%j==0)
                p[i]=p[i]+j;
        }
        //cout << p[i] << endl;
    }
    int k = 0;
    for (int i = n; i <m;i++)
    {
        for (int j = i+1; j <= m;j++)
        {
            if (p[i] == j && i == p[j])
            {
                k = 1;
                cout << i <<" "<< j << endl;
            }
        }
    }
    if(k==0)
        cout << "NONE" << endl;
    delete[] p;
    system("pause");
    return 0;
}