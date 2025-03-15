#include<iostream>
#include<utility>

using namespace std;

//代替二元结构体
//作为map键值对进行插入

int main()
{
    //1.初始化定义
    pair<string, int> p;//不带初始值的
    pair<string, int> p1("wangyaqi",1);//带初始值的

    //2.赋值
    p = {"wang", 18};
    //p = make_pair("wang", 18);
    //p = pair<string, int>("wang", 18);

    system("pause");
    return 0;
}