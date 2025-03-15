#include<iostream>
using namespace std;
template <class numtype>    //定义类模板;
class compare
{
    public:
        compare(numtype a, numtype b);
        numtype max();
        numtype min();
    private:
        numtype x, y;
};
template<class numtype>
compare<numtype>::compare(numtype a, numtype b)
{
    x = a;
    y = b;
}
template <class numtype>                    //类模板外定义成员函数;
numtype compare<numtype>::max()
{
    return (x > y) ? x : y;
}
template<class numtype>
numtype compare<numtype>::min()
{
    return (x < y) ? x : y;
}
int main()
{
    compare<int> cmp1(3, 7);
    cout << cmp1.max() << " is the Maximum of two integer numbers." << endl;
    cout << cmp1.min() << " is the Minimum of two integer numbers." << endl
         << endl;
    compare<float> cmp2(36.5, 23.9);
    cout << cmp2.max() << " is the Maximum of two float numbers." << endl;
    cout << cmp2.min() << " is the Minimum of two float numbers." << endl
         << endl;
    compare<char> cmp3('a', 'A');
    cout << cmp3.max() << " is the Maximum of two char numbers." << endl;
    cout << cmp3.min() << " is the Minimum of two char numbers." << endl
         << endl;
    system("pause");
    return 0;
}