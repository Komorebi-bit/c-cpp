#include<iostream>
#include<string>
using namespace std;
//字符串排序
int main()
{
    string s[5];
    int i ,j;
    for (i = 0; i < 5; i++)
    {
        cin >> s[i];
    }
    for (i = 0; i < 5;i++)
    {
        for (j =0 ; j <4-i ;j++)
        {
            string t;
            if(s[j]>s[j+1])
            {
                t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    for (i = 0; i < 5;i++)
    {
        cout << s[i]<<endl;
    }
    system("pause");
    return 0;
}