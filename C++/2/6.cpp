#include<iostream>
using namespace std;

class food
{
    public:
        food(int x = 2, int y = 5) : a(x), b(y){};
        void output();
    private:
        int a;
        int b;
};
void food::output()
{
    cout << a << endl
         << b << endl;
}
int main()
{
    int sum(int);
    food f1(12,15), f2;
    int m=3;
    int (*p)(int) = sum;
    void (food::*p2)() = &food::output;
    (f1.*p2)();
    cout << (*p)(m) << endl;
    system("pause");
    return 0;
}
int sum(int s)
{
    return 2 * s;
}