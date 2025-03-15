#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(b*b-4*a*c<0)
    {
        float x = -b / (2 * a * 1.0);
        float y = sqrt((b * b - 4 * a * c) * (-1)) / (2 * a * 1.0);
        cout << setiosflags(ios::fixed) << setprecision(2) << x << "+"
             << setiosflags(ios::fixed) << setprecision(2) << y << "i" <<" "
             << setiosflags(ios::fixed) << setprecision(2) << x << "-"
             << setiosflags(ios::fixed) << setprecision(2) << y << "i" << endl;
    }
    else
        {
            float x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a * 1.0);
            float x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a * 1.0);
            if (x1 != x2)
                cout << setiosflags(ios::fixed) << setprecision(2) << x1
                     << " " << setiosflags(ios::fixed) << setprecision(2) << x2 << endl;
            else
                cout << setiosflags(ios::fixed) << setprecision(2) << x1 << endl;
        }
    system("pause");
    return 0;
}