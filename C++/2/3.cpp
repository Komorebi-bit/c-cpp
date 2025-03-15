//C++面向对象程序设计学习与练习;
#include<iostream>
using namespace std;

class complex
{
    public:
        complex() { real = 0, imag = 0; }//构造函数
        complex(double r,double i):real(r),imag(i){}//带参数的构造函数
        ~complex() { cout << "destructor called" << endl; }//析构函数
        operator double(){ return real; }//类型转换函数
        complex(double t) {real = t, imag = 0;} //转化构造函数
        friend complex operator+(const complex &, const complex &);
        friend complex operator+(const complex &, const double &);
        friend complex operator+(const double &, const complex &);
        friend complex operator-(const complex &, const complex &);         //重载运算符
        friend istream& operator>>(istream &, complex &);
        friend ostream& operator<<(ostream &, const complex &);
        friend bool operator==(const complex &, const complex &);
        static void counter();
    private:
        double real;
        double imag;
        static int count;
};
int complex::count = 0;
void complex::counter()
{
    count++;
    cout << count << endl;
}
complex operator +(const complex& c1,const complex& c2)
{
    return complex(c1.real + c2.real, c1.imag + c2.imag);
}
complex operator +(const double& t,const complex& c2)
{
    return complex(t + c2.real, c2.imag);
}
complex operator +(const complex& c1,const double& t)
{
    return complex(c1.real + t, c1.imag);
}
complex operator -(const complex& c1,const complex& c2)
{
    return complex(c1.real - c2.real, c1.imag - c2.imag);
}
bool operator==(const complex & c1, const complex& c2)
{
    if(c1.real==c2.real&&c1.imag==c2.imag)
        return true;
    else
        return false;
}
istream& operator >>(istream& input, complex& c)
{
    cout << "input real part and imaginary part of complex number: ";
    input >> c.real >> c.imag;
    return input;
}
ostream& operator <<(ostream& output, const complex& c)
{
    output << c.real;
    if(c.imag>=0)
        output << "+";
    output<< c.imag <<"i"<< endl;
    return output;
}

int main()
{
    complex c1(1, 5), c2(2, 7), c3,c4;
    double t = 5;
    c1.counter();
    complex::counter();
    c3 = t + c1;
    cout << c3 << endl;
    c3 = c1;
    cout << c3 << endl;
    c3 = c1 + c2;
    cout << c3 << endl;
    cin >> c1 >> c2;
    c3 = c1 + c2;
    cout << c3<<endl;
    c4 = t;
    c3 =  c4+ c1;
    cout << c3<<endl;
    t = c1 - c2;
    cout << t<<endl;
    cout << (c1 == c2) << endl;
    system("pause");
    return 0;
}