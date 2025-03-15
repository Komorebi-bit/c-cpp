//按照字符顺序从小到大进行排序，并删除重复的字符
#include<iostream>
#include<string.h>
using namespace std;
const int n = 100;
int main()
{
    char a[n];
    char b[n];
    cin.get(a,n);
    int len = strlen(a);
    int b_len = 0;
    for (int i = 0; i < len;i++)
    {
        int t = 0;
        for (int  k= 0; k < b_len;k++)
        {
            if(b[k] == a[i])
            {
                t = 1;
                break;
            }
        }
        if(t==0)
        b[b_len++] = a[i];
    }
//    for (int k = 0; k < b_len;k++)
//        cout << b[k] << " ";
//    cout << endl;
    for (int i = 0; i < b_len; i++)
        for (int j = 0; j < b_len - i - 1; j++)
            if (b[j] > b[j + 1])
            {
                char temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
    for (int k = 0; k < b_len;k++)
        cout << b[k];
    system("pause");
    return 0;
}