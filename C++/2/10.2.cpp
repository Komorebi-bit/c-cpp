#include <iostream>
using namespace std;

long long N;
long long sum;

int main()
{
    cin>>N;
    int x=0;
    long long int add(long long int n);
    long long sub(long long int n);
    x=add(0);
    cout<<sub(x)<<endl;
    system("pause");
    return 0;
}
long long int add(long long int n)
{
    sum+=n;
    if(n==N)
    {
        return n;
    }
    if(n<N)
    {
        n++;
        return add(n);
    }
}
long long sub(long long int n)
{
    if(n==0)
    {
        return sum;
    }
    n--;
    sum+=n;
    return sub(n);

}


