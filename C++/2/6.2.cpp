#include<iostream>
using namespace std;
//统计在冒泡排序过程种数据交换的次数
int main()
{
    int n,count=0;
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
                count++;
            }
    cout << count << endl;
    delete[] p;
    system("pause");
    return 0;
}