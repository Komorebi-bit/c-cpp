#include<iostream>
using namespace std;
//排序
int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n;i++)
        cin >> p[i];
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n-i-1;j++)
            if(p[j]>p[j+1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
    for (int i = 0; i < n;i++)
        cout << p[i]<<" ";
    delete[] p;
    system("pause");
    return 0;
}