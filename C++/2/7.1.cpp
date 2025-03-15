#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int loop(int);
    for (int i = a; i <= b; i++)
    {
        if(loop(i))
            cout << loop(i) << endl;
    }
    system("pause");
    return 0;
}
int loop(int x)
{
    int t = x, sum = 0;
    while (t)
    {
        sum = sum * 10 + t % 10;
        t = t / 10;
    }
    if (sum == x)
        return x;
    else
        return 0;
}