#include<iostream>
using namespace std;
//求n的k次幂;
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int recursion(int, int);
    cout << recursion(n, k) << endl;
    system("pause");
    return 0;
}
int recursion(int n,int k)
{
    if(0==k)
        return 1;
    k--;
    return n * recursion(n, k);
}