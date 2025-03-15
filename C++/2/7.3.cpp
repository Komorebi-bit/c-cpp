#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b;i++)
    {
        int j = i * i;
        if(i<10)
        {
            if(i==j)
                cout<<i<<endl;
            else
            {
                if(i==(j%10))
                    cout << i << endl;
            }
        }
        else
        {
            if(i==(j%100))
                cout << i << endl;
        }
    }
    system("pause");
    return 0;
}