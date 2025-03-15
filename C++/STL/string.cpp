#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    //支持比较运算符，支持+运算符（字符串拼接）

    // 容器的初始化
    string str1 = "abc";
    string str2(3, 'i'); //  ="iii"
    string str3("i love u");
    string str4(str3, 2, 4); // 从下标2的字符开始，长度为4

    //读入字符串，遇空格、回车结束
    cin >> str;

    //读入一行字符串（包括空格），遇回车结束
    //会获取前一个输入的换行符，需要在前面添加读取换行符的语句。
    //如：getchar() 或 cin.get()
    getline(cin, str);

    //返回string对象的字符个数
    str.size();
    str.length();

    //在末尾插入
    //在0位置插入'A'
    //在str字符串结尾添加str_字符串
    string str_ = "xyz";
    str.push_back('1');
    str.insert(0, 'A');
    str.append(str_);

    // 删除
    // pop_back()
    // erase(iterator p)	删除字符串中p所指的字符
    // erase(iterator first, iterator last)	删除字符串中迭代器区间[first,last)上所有字符
    // erase(pos, len)	删除字符串中从索引位置pos开始的len个字符
    // clear()	删除字符串中所有字符

    // 替换
    // s.replace(pos,n,str)	把当前字符串从索引pos开始的n个字符替换为str
    // s.replace(pos,n,n1,c)	把当前字符串从索引pos开始的n个字符替换为n1个字符c
    // s.replace(it1,it2,str)	把当前字符串[it1,it2)区间替换为str it1 ,it2为迭代器哦

    // 类型转换
    // stoi(s)	将字符串 s 转化为 int 类型
    // stoll(s)	将字符串 s 转化为 long long int 类型
    // stod(s)	将字符串 s 转化为 double 类型
    // stold(s)	将字符串 s 转化为 long double 类型

    // 截取
    // s.substr(pos,n)	截取从pos索引开始的n个字符


    // 查找
    // s.find (str, pos)	在当前字符串的pos索引位置（默认为0）开始，查找子串str，返回找到的位置索引，-1表示查找不到子串
    // s.find (c, pos)	在当前字符串的pos索引位置（默认为0）开始，查找字符c，返回找到的位置索引，-1表示查找不到字符

    // 排序 <algorithm>
    //sort(s.begin(),s.end());  //按字符的ASCII码排序

    // 字符串反转
    //reverse(s.begin(), s.end());

    /*
    将string类的字符串转换成c类型的字符串
    string str="abc";
    char s1[100];
    strcpy(s1, str.c_str()); <cstring>
    */

    // 将数值val转换为string，val可以是任何算术类型（int、浮点型等）
    // to_string(val);  <string> c++11

    system("pause");
    return 0;
}