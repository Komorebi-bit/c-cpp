#include<iostream>
#include<string.h>
#include<string>
using namespace std;

class people
{
    public:
        people(string nam,int a,string s):name(nam),age(a),sex(s){}
        ~people(){};
        void display()
        {
            cout << "name: " << name << endl
                 << "age: " << age << endl
                 << "sex: " << sex << endl;
        }
    protected:
        string name;
        int age;
        string sex;
};

class teacher:virtual public people  //虚基类
{
    public:
        teacher(string nam,int a,string s,string t):people(nam,a,s),title(t){}
        ~teacher(){};
        void display()
        {
            cout << "title: " << title << endl;
        }
    protected:
        string title;
};

class student:virtual public people
{
    public:
        student(string nam,int a,string s,float sco):people(nam,a,s),score(sco){}
        ~student(){};
        void display()
        {
            cout << "score: " << score << endl;
        }
    protected:
        float score;
};

class graduate:public teacher,public student
{
    public:
        graduate(string nam,int a,string s,string t,float sco,float w):
            people(nam,a,s),teacher(nam,a,s,t),student(nam,a,s,sco),wage(w){}
        ~graduate(){};
        void show()
        {
            cout << "name: " << name << endl
                 << "age: " << age << endl
                 << "sex: " << sex << endl
                 << "title: " << title << endl
                 << "score: " << score << endl
                 << "wage: " << wage << endl;
        }
    private:
        float wage;
};

int main()
{
    graduate grad1("wang li", 24, "boy", "assistance", 96.5, 2400);
    grad1.show();
    system("pause");
    return 0;
}