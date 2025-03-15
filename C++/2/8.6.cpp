#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *max_r = new int[n + 1];
    for (int i = 0; i < n + 1;i++)
        max_r[i] = -10000;
    int *max_c = new int[m + 1];
    for (int i = 0; i < m + 1;i++)
        max_c[i] = -10000;
    int **p = new int *[n + 1];
    for (int i = 0; i < n + 1;i++)
        p[i] = new int[m + 1];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
        {
            cin >> p[i][j];
            max_r[i] = max((p[i][j]),max_r[i]);
            max_c[j] = max((p[i][j]),max_c[j]);
        }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            if(max_r[i]==max_c[j])
                cout << max_r[i] << " " << i << " " << j << endl;
    delete[] max_r;
    delete[] max_c;
    for (int i = 0; i < n + 1;i++)
        delete[] p[i];
    delete[] p;
    system("pause");
    return 0;
}