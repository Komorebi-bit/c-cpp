#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int n;
    double a, b;
    cin >> n;
    int *p = new int[n];

    for (int i = 0; i < n;i++)
    {
        cin >> p[i];
    }
    void f(int n, int *p, double *a, double *b);
    f(n, p, &a, &b);
    cout << setiosflags(ios::fixed) << setprecision(2)<< a
    << " " << setiosflags(ios::fixed) << setprecision(2) << b
    << endl;
    system("pause");
    return 0;
}
void f(int n,int*p,double*a,double*b)
{
    double sum=0;
    for (int i = 0; i < n;i++)
    {
        sum += p[i];
    }
    *a = sum / (n*1.0);
    sum = 0;
    for (int i = 0; i < n;i++)
    {
        sum += ((*a) - p[i]) * ((*a) - p[i]);
    }
    *b = sqrt(sum/(n*1.0));
}