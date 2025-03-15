#include<iostream>
using namespace std;
int isprime(int n)
{
    if(n==1)
        return 1;
    else
    {
        int i = 2;
        while(i!=n)
        {
            if(n%i==0)
                return 0;
            i++;
        }
        if(i==n)
            return 1;
    }

}
int main()
{
    int n;
    cin >> n;
    cout << isprime(n) << endl;
    //system("pause");
    return 0;
}