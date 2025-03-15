#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int recursion(int);
    cout << recursion(t) << endl;
    system("pause");
    return 0;
}
int recursion(int t)
{
    if(1==t)
        return 1;
    t--;
    return (recursion(t) + 1) * 2;
}