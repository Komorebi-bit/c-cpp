#include <iostream>
#include <map>

//map：红黑树实现，头文件<map>
//unordered_map：哈希表实现，头文件<unordered_map>

using namespace std;

int main()
{
    map<int, string> mp;

    // 容器的初始化
    mp[-1] = "read";
    map<int, char> mp1 = {{1, '#'}, {2, '$'}, {3, '@'}};

    mp.insert(make_pair(-2, "play game"));
    mp.insert(pair<int, string>(-3, "write"));
    mp.insert({-4, "run"});

    //遍历访问
    //方式一：迭代器访问
    map<int,string>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++) {
	    //      键                 值
	    // it是结构体指针 访问所以要用 -> 访问
	    cout << it->first << " " << it->second << "\n";
	    //*it是结构体变量 访问要用 . 访问
	    //cout<<(*it).first<<" "<<(*it).second;
    }

    //方式二：智能指针访问
    for(auto i : mp)
    cout << i.first << " " << i.second << endl;//键，值

    //方式三：对指定单个元素访问
    it = mp.find(0);
    if(it!=mp.end()) //mp.end()返回值无法输出出来
        cout << it -> first << " " <<  it->second << "\n";

    //方式四：c++17特性才具有
    //for(auto [x, y] : mp)
	//   cout << x << " " << y << "\n";
    //x,y对应键和值


    //map<int, string>::iterator it;
    int key = -1;
    //返回键为key的映射的迭代器 注意：用find函数来定位数据出现位置，它返回一个迭代器。当数据存在时，返回数据所在位置的迭代器，数据不存在时，返回mp.end() O(logN)
    it = mp.find(key);
    //删除迭代器对应的键和值 O(logN)
    mp.erase(it);
    //根据映射的键删除键和值 O(logN)
    mp.erase(key);
    //删除左闭右开区间迭代器对应的键和值 O(last−first)
    //first, last迭代器
    //mp.erase(first, last);
    //返回映射的对数 O(1)
    mp.size();
    //插入元素，插入时要构造键值对 O(logN)
    // mp.insert();
    //如果map为空，返回true，否则返回false O(1)
    mp.empty();
    //返回指向map第一个元素的迭代器（地址） O(1)
    mp.begin();
    //返回指向map尾部的迭代器（最后一个元素的下一个地址） O(1)
    mp.end();
    //清空map中的所有元素 O(N)
    mp.clear();

    //at()函数：根据key查找哈希表中的元素
    //使用at，找不到，抛out_of_range异常
    // map<int, int> mp{ {1,10},{2,12},{3,13} };
    // int elem = mp.at(3);
    //使用[]，不存在就创建出来


    system("pause");
    return 0;
}
