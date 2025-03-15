#include<iostream>
using namespace std;

int main()
{
    int a[40], b[40];
    int n,i;
    cin >> n;
    for (i = 0; i < n;i++)
        cin >> a[i];
    int m;
    cin >> m;
    for (i = n; i < n+m;i++)
        cin >> a[i];
    int len = 0;
    for (i = 0; i < m + n;i++)
    {
        int k = 0;
        for (int j = 0; j < m + n;j++)
        {
            if(i!=j)
            {
                if(a[i]==a[j])
                {
                    k = 1;
                    break;
                }
            }
        }
        if(k==0)
            b[len++] = a[i];
    }
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
    for (int i = 0; i < len ;i++)
        cout << b[i]<<" ";
    system("pause");
    return 0;
}