#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int kk = 0;
    for (int i = 11; i <= n;i++)
    {
        int k = 0;
        for (int j = 2; j < i;j++)
        {
            if(i%j==0||i%10!=1)
            {
                k = 1;
                break;
            }
        }
        if(k==0)
        {
            cout << i <<" ";
            kk = 1;
        }
    }
    if(kk==0)
        cout << -1 << endl;
    system("pause");
    return 0;
}