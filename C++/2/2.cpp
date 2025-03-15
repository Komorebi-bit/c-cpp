#include <iomanip>
#include <iostream>
using namespace std;

const double PI = 3.14159;

template <typename T>
T sum(T a, T b, T c)
{
    T sum = a + b + c;
    return sum;
}

int main()
{
    int a, b, c;
    float x, y, z;
    long m, n, t;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    cin >> m >> n >> t;
    cout << sum(a, b, c) << endl;
    cout << sum(x, y, z) << endl;
    cout << sum(m, n, t) << endl;
    cout << PI << endl;
    system("pause");
    return 0;
}