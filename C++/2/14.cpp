/*
声明一个Teacher(教师)类 和 一个Student(学生)类，二者有一部分数据成员是相同的，
例如num(号码),name(姓名),sex(性别)。编写程序，将一个Student对象（学生）转换成Teacher（教师）类，
只将以上三个相同的数据成员移植过去。
可以设想为：一位大学生毕业了，留校担任老师，
他原有的部分数据对现在的教师身份来说仍然是有用的，
应当保留并成为其教师数据的一部分。
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;


class Student{
public:
    Student(int,char[],char,float);
    int get_num(){return num;}
    char*get_name(){return name;}
    char get_sex(){return sex;}
    void display();
private:
    int num;
    char name[20];
    char sex;
    float score;
};



class Teacher{
public:
    Teacher(){}
    Teacher(Student&);
    Teacher(int n,char nam[],char sex,float pay);
    void display();
private:
    int num;
    char name[20];
    char sex;
    float pay;
};

int main(){
    Teacher teacher1(10001,"chen",'w',19447) , teacher2;
    Student student1(2020414000,"gu",'m',96.5);
    cout<<"student1:"<<endl;
    student1.display();
    teacher2=Teacher(student1);
    cout<<"teacher2:"<<endl;
    teacher2.display();
    system("pause");
    return 0;
}


Student::Student(int n,char nam[],char s,float sco):sex(s){
    num=n;
    strcpy(name,nam);
    score=sco;
}


Teacher::Teacher(Student&stud){
    num=stud.get_num();
    strcpy(name,stud.get_name());
    sex=stud.get_sex();
    pay=4500;
}


Teacher::Teacher(int n,char nam[],char s,float p):sex(s){
    num=n;
    strcpy(name,nam);
    pay=p;
}


void Teacher::display(){
    cout<<"num:"<<num<<endl<<"name:"<<name<<endl<<"sex:"<<sex<<endl<<"pay:"<<pay<<endl<<endl;
}


void Student::display(){
    cout<<"num:"<<num<<endl<<"name:"<<name<<endl<<"sex:"<<sex<<endl<<"score:"<<score<<endl<<endl;
 }
