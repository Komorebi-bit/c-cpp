//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm> //含有unique去重函数;
using namespace std;

int main()
{
    char s[] = "asdfg";
    char s1[] = "asd";
    cout << strcpy(s,0,1) << endl;
    system("pause");
    return 0;
}
/*
数组作为函数参数;
int a[n];
void sort(int[]);
sort(a);
void sort(int a[]);

<<(x) :乘以2的x次方;
>>(y) :除以2的y次方;
&  按位与;

unique 去重函数
    int ans = unique(a, a + k) - a;
    数组a,数组长度k,返回值ans是不重复的后下一位的下标;
    例如:a={0,1,2,3,4,0,0,0,0}ans是第二个0的下标;
1.getline()函数 (#include<string>)
    string s;
	getline(cin,s);
	cout << s << endl;
2.cin.get(char *str,int maxnum) 可以接收空格，遇回车结束输入
    char s[50];
	cin.get(s,50);
	cout << s <<endl;//也可以printf("%s",s);
3.cin.getline (char *str, int maxnum) (#include <string>)可接收空格，遇回车结束输入.
    char s[50];
	cin.getline(s,50);
	cout << s << endl;//也可以printf("%s",s);

int *p=new int[5];    //动态申请一维数组
delete[] p;
int **p=new int*[5];    //二维数组
for(int i=0;i<5;i++)
{
    p[i]=new int[5];
    delete[] p[i];
}
delete []p;

    加入setprecision(n)  设置浮点数有效数字
    cout<<setprecision(3)<<a<<endl;        //将精度改为3（即有效数字三位） 输出3.14
    cout<<setprecision(10)<<a<<endl;    //将精度改为10  输出3.141592654

    加入setiosflags(ios::fixed)   设置浮点数以固定的小数位数显示
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<a<<endl;
    控制精度为小数位  setprecision(3)即保留小数点2位    输出3.14

    不能重载的运算符5个:
            .   (成员访问运算符)
            *   (成员指针访问运算符)
            ::  (域运算符)
            sizeof  (长度运算符)
            ?:  (条件运算符)
*/