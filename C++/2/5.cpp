#include<iostream>
#include<string>
using namespace std;
class A
{
    public:
        A()
        {
            num = 2020618;
            name = "译名";
            s = 3.14;
        }
        void display();
    private:
        int num;
        string name;
        float s;
};
void A::display()
{
    cout << num << endl
         << name << endl
         << 2 * s << endl
         << endl;
}
class B
{
    public:
        B(int, string, float);
        void display();
    private:
        int num;
        string name;
        float s;
};
B::B(int b1,string b2,float b3)
{
    num = b1;
    name = b2;
    s = b3;
}
void B::display()
{
    cout << num << endl
         << name << endl
         << 2 * s << endl
         << endl;
}
class C
{
    public:
        C(int c1 = 2020618, string c2 = "译名", double c3 = 3.1414926535, char c4 = 'm');
        //C(int c1 = 2020618, string c2 = "译名", double c3 = 3.1413962535, char c4 = 'm'):num(c1),
        //name(c2), s(c3), e(c4){};
        void display();
    private:
        int num;
        string name;
        double s;
        char e;
};
C::C(int c1 , string c2 , double c3 , char c4)
{
    num = c1;
    name = c2;
    s = c3;
    e = c4;
}
void C::display()
{
    cout << num << endl
         << name << endl
         << s << endl
         << e << endl
         << endl;
}

int main()
{
    A a;
    A *p;
    p = &a;
    void(A::*p1)();
    p1 = &A::display;
    p->display();
    (*p.*p1)();
    a.display();
    B b(2020618, "译名", 3.1415926);
    b.display();
    C c1,c2(2020999,"译名哦",3.1415926*2);
    c1.display();
    c2.display();
    system("pause");
    return 0;
}