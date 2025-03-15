#include<iostream>
using namespace std;

class a
{
    public:
        a(int xx):x(xx){}
        void display()
        {
            cout << "x: " << x << endl;
        }
    protected:
        int x;
};

class b:public a
{
    public:
        b(int xx,int xxx,int yy):a(xx),aa(xxx),y(yy){}
        void display()
        {
            cout << "x: " << x << endl;
            cout << "y: " << y << endl;
            //cout << "aa.x: " << aa.x << endl;
        }
    protected:
        a aa;                   //有子对象;
        int y;
};

class c:public b
{
    public:
        c(int xx, int xxx,int yy,int zz):b(xx,xxx,yy),z(zz){}
        void display()
        {
            cout << "x: " << x << endl;
            cout << "y: " << y << endl;
            cout << "z: " << z << endl;
            aa.display();
        }
    private:
        int z;
};

int main()
{
    c c1(1, 22, 2, 3);
    c1.display();
    system("pause");
    return 0;
}