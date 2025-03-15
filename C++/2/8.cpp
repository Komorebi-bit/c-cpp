#include<iostream>
using namespace std;

class A
{
    public:
        A(int a = 1, int b = 2) : x(a), y(b) {};
        void show() const;
        void put();
    private:
        int x;
        int y;
};
void A::show() const
{
    cout << x << " " << y <<endl;
}
void A::put()
{
    cin >> x >> y;
}

int main()
{
    const A a1;
    A a2(3, 5);
    a1.show();
    //a2.put();
    a2.show();
    int x = 1, y = 2;
    int sum(const int &, int &);
    int s = sum(x, y);
    cout << s << endl;
    system("pause");
    return 0;
}
int sum(const int &a,int &b)
{
    //b= 4;
    int sum = a + b;
    return sum;
}