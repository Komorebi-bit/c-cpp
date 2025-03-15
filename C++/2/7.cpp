#include<iostream>
using namespace std;
class complex
{
    private:
        double real;
        double imag;
    public:
        complex()
        {
            real = 0;
            imag = 0;
        }
        complex (double r)
        {
            real = r;
            imag = 0;               //似乎没啥用
        }
        operator double () { return real;}
        complex(double r,double i):real(r),imag(i){}
        ~complex(){}
        complex operator+(complex &c)
        {
            complex c1;
            c1.real = real + c.real;
            c1.imag = imag + c.imag;
            return c1;
        }
        complex operator+(double &d)
        {
            complex c;
            c.real = real + d;
            c.imag = imag;
            return c;
        }
        void show()
        {
            cout << real << "+" << imag << "i" << endl;
        }
};

int main()
{
    complex c1(3.3, 5.5), c2(1.1, 6.6), c3;
    double d = 3.3;
    c3 = c1 + d;
    d = c2 + d;
    c3 = d + c1;
    c3.show();
    cout << d << endl;
    system("pause");
    return 0;
}