#include <algorithm> //unique去重//int num[10]//int ans=unique(num,num+10)-num;
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n = 0, k = 0;
    int a[1000] = {0};
    cin >> n;
    long long p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j <= p[i]; j++)
        {
            if ((p[i]) % j == 0)
            {
                while ((p[i]) % j == 0 && p[i]!=1)
                    p[i] = p[i] / j;
                a[k++] = j;
            }
            if(p[i]==1)
                break;
        }
    }
    void sort(int *a, int k);
    sort(a, k);
    int ans = unique(a, a + k) - a;
    for (int i = 0; i < ans; i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
void sort(int *a, int k)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}