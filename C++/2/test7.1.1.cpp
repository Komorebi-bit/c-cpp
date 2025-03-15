#include<iostream>
using namespace std;
const double PI = 3.1415926;
class point
{
    public:
        point(float i,float j):x(i),y(j){}
        virtual double integral()
        {
            return 0;
        }
    protected:
        float x, y;
};
class circle:public point
{
    public:
        circle(float i,float j, float k):point(i,j),r(k){}
        virtual double integral()
        {
            return PI * r * r;
        }
    protected:
        float r;
};
class cylinder:public circle
{
    public:
        cylinder(float i,float j,float k,float l):circle(i,j,k),h(l){}
        virtual double integral()
        {
            return PI * r * r * h;
        }
    private:
        float h;
};
int main()
{
    point po(1, 1);
    circle ci(1, 1, 2);
    cylinder cy(1, 1, 2, 5);
    point *p1 = &po;
    cout << p1->integral() << endl;
    p1 = &ci;
    cout << p1->integral() << endl;
    p1 = &cy;
    cout << p1->integral() << endl;
    system("pause");
    return 0;
}