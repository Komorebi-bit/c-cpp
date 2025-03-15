#include <iostream>
// iostream包含了cstdio，cmath，cstdlib，stdexcept，exception，climits 等头文件
// max(),min(),swap()方法

#include <cstring>
// memcpy(a,b,sizeof a), 把数组b复制给a；
/*
memset(a,0,sizeof a) 把数组a赋值为0
若str指向char型地址，value可为任意字符值；
若str指向非char型，如int型地址，要想赋值正确，value的值只能是-1或0，因为-1和0转化成二进制后每一位都是一样的，设int型占4个字节，则-1=0XFFFFFFFF, 0=0X00000000。
memset初始化为无穷大,memset(a , 0x3f , sizeof a);
*/

#include <algorithm>
// 含有unique去重函数,
// reverse(),binary_search(),count(),merge(),
// sort(begin, end, cmp),cmp是一个返回值为bool型的函数，可以写也可不写;
// bool cmp(int&, int&); 引用（值传递也行）
/*
交集set_intersection()、并集set_union()、差集set_difference()和对称差集set_symmetric_difference()
参数：iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest
beg1 容器1开始迭代器
end1 容器1结束迭代器
beg2 容器2开始迭代器
end2 容器2结束迭代器
dest 目标容器开始迭代器，提前分配好空间resize()
*/

#include <unordered_map>
// 哈希表可以使用unordered_map
// 堆可以使用priority_queue


// #define MAX  0x3f3f3f3f
//  C++ 全局变量存储在 堆空间 中，局部变量存储在 栈空间 中

// exit(0);终止程序的执行，0表示成功，非0表示失败，位于头文件<cstdlib>中 排除异常位置时使用

// 判断一个数是否小于等于其算数平方根 i <= n / i

// 如何让 Dev C++ 支持 C++11
// 依次点击：Tools -> compiler Options
// 然后在 compiler Options 界面勾选 Add the following commands when calling the compiler ，
// 在其下面的框中添加 -std=c++11 命令，最后点击 OK 即可。

// #define  _for(i, a, b) for (int i = (a); i <= (b); ++i) //for循环

#define DEBUG // 调试时把他打开
/*
    #ifdef DEBUG
    // do something when DEBUG is defined
    #endif
    // or
    #ifndef DEBUG
    // do something when DEBUG isn't defined
    #endif
*/

using namespace std;

// const int INF = 0x3f3f 3f3f; 可以当作int型无穷大数用，写下命名空间下面
// int型最大值0x7fff ffff

// 擅用namespace,解决变量名冲突问题
/*
namespace my{
    可以定义变量，函数，类型
    int a;
    int func();
}
使用：my::a，my::func()
*/

struct node
{
    int n;
    unordered_map<int, int> mp;
};

int main()
{
    struct node p;
    p.n = 123;
    p.mp[1] = 123;
    // cout << endl;
    cout << p.n << ' ' << p.mp[1] << '\n';
    // string s = "abc";
    // int i = 1;
    // s += i+'0';
    // cout << s << endl;

    // _for(i,0,10) //for循环
    // {
    //     cout << i << " ";
    // }
    // printf("%d\n", MAX);

    // exit(0); //排除异常位置时使用

    // #ifdef DEBUG
    //     cout << "Debug.." << endl; //调试时运行此代码
    // #endif
    // // or
    // #ifndef DEBUG
    //     cout << "Not Debug" << endl; //非调试时运行此代码
    // #endif

    system("pause");
    return 0;
}

/*

c++11 用nullptr代替NULL
--------------------------------------------------------
&&，||：若第一个表达式（左边的）为假，不会计算第二个表达式
&，|：会计算所有的表达式
--------------------------------------------------------
scanf()函数返回值：
    scanf函数接收数据成功的返回值为接收数据个数（一个%d（或%c等）的格式只能算一个数）
    scanf函数接收数据失败的返回值-1（EOF默认为-1），当输入格式不符的时候，返回值为0
--------------------------------------------------------
数组作为函数参数,传递的是数组首地址
int a[n];
void sort(int[]);
sort(a);
void sort(int a[]);
--------------------------------------------------------
string类型变量作为函数参数，是值传递
--------------------------------------------------------
<<(x) :乘以2的x次方;
>>(y) :除以2的y次方;
&  按位与;
--------------------------------------------------------
abs()绝对值函数
sqrt()平方根函数
--------------------------------------------------------
unique 去重函数
    int ans = unique(a, a + k) - a;
    数组a,数组长度k,返回值ans是不重复的后下一位的下标;
    例如:a={0,1,2,3,4,0,0,0,0}ans是第二个0的下标;
1.getline()函数 (#include<string>)
    string s;
    getline(cin,s);
    cout << s << endl;
  - 若在getline前使用了cin，scanf函数，需要用getchar()或者cin.get()把换行符吃掉
2.cin.get(char *str,int maxnum) 可以接收空格，遇回车结束输入
    char s[50];
    cin.get(s,50);
    cout << s <<endl;//也可以printf("%s",s);
3.cin.getline (char *str, int maxnum) (#include <string>)可接收空格，遇回车结束输入.
    char s[50];
    cin.getline(s,50);
    cout << s << endl;//也可以printf("%s",s);
--------------------------------------------------------
int *p=new int[5];    //动态申请一维数组
delete[] p;
int **p=new int*[5];    //二维数组
for(int i=0;i<5;i++)
{
    p[i]=new int[5];
    delete[] p[i];
}
delete []p;
--------------------------------------------------------
加入setprecision(n)  设置浮点数有效数字
cout<<setprecision(3)<<a<<endl;        //将精度改为3（即有效数字三位） 输出3.14
cout<<setprecision(10)<<a<<endl;    //将精度改为10  输出3.141592654

加入setiosflags(ios::fixed)   设置浮点数以固定的小数位数显示
cout<<setiosflags(ios::fixed)<<setprecision(2)<<a<<endl;
控制精度为小数位  setprecision(3)即保留小数点2位    输出3.14
--------------------------------------------------------
不能重载的运算符5个:
        .   (成员访问运算符)
        *   (成员指针访问运算符)
        ::  (域运算符)
        sizeof  (长度运算符)
        ?:  (条件运算符)
--------------------------------------------------------
指针、引用
    指针	变量，独立，可变，可空，替身，无类型检查
    引用	别名，依赖，不变，非空，本体，有类型检查

    int a = 996;
    int *p = &a; // p是指针, &在此是求地址运算
    int &r = a; // r是引用, &在此起标识作用

    指针 可以在定义的时候不初始化，  引用 必须在定义的时候初始化
    指针 可以指向NULL，             引用 不可以为NULL
    指针 初始化之后可以再改变，      引用 不可以

    函数声明：void func(int *p){}  函数调用：func(&x) 指针参数
    函数声明：void func(int &a){}  函数调用：func(x)  引用参数
--------------------------------------------------------
for(auto i: str){cout<<i<<' ';} 也可以是引用&i
    适用于 std::string、vector、array、set 等支持 begin() 和 end() 迭代的容器。

--------------------------------------------------------
结构体
    struct node  //定义结构体，未分配内存空间
    {
        int a;
        char c;
    };
    struct node p; //创建结构体变量，为其分配内存
    --------------------------------------------------------
    struct node   //和上面的等效
    {
        int a;
        char c;
    }p;   //创建结构体变量，为其分配内存
    --------------------------------------------------------
    typedef 定义新类型，一般格式为；typedef 已有类型 新类型名;
    typedef struct node
    {
        int a;
        char c;
    }TNode;
    TNode p; //或者struct node p;
--------------------------------------------------------
*/