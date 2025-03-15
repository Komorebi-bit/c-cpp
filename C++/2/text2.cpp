#include<iostream>
using namespace std;
int main()
{
    //void com(int*, int*);
    void com(int &, int &);
    int x, y;
    cin >> x >> y;
    //com(&x, &y);
    com(x, y);
    cout << x <<" "<< y << endl;
    system("pause");
    return 0;
}
/*void com(int *p1,int *p2)
{
    int tem;
    if(*p1<*p2)
    {
        tem = *p1;
        *p1 = *p2;
        *p2 = tem;
    }
}*/
void com(int &a,int &b)
{
    int temp;
    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }
}