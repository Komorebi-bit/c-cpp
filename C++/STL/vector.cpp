#include <iostream>
#include <vector>

using namespace std;

// vector（矢量），是一种「变长数组」，即“自动改变数组长度的数组”

int main()
{
    vector<int> v;
    // vector<struct node> name;
    // vector<vector<int>> name;

    // 容器的初始化
    // vector<int> v1 = {1, 2, 3, 4, 5};
    // vector<int> v2(n);     // n个0元素
    // vector<int> v3(n, -1); // n个-1元素
    // vector<int> v4(v0);    // 用v0（vector）初始化
    // vector<int> v5(p, q);  // 使用指针（vector指针、数组指针）来初始化，p数组首地址，q长度

    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);

    // 一、访问容器元素
    //     （1）通过下标访问
    //     （2）通过迭代器访问
    vector<int>::iterator it;
    // v.begin()返回v的首元素地址
    it = v.begin();

    for (int i = 0; i < (int)v.size(); i++)
        cout << it[i] << " ";
    // cout<<*(it+i)<<" ";
    cout << endl;

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // vector后面添加一个元素item。
    int item = -2;
    v.push_back(item);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    // 一次弹出一个元素
    v.pop_back();
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    // 返回容器中元素的个数
    v.size();

    // 将-1插入v[2]的位置
    v.insert(v.begin() + 2, -1);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    // 删除v[3]
    v.erase(v.begin() + 3);
    for(auto i: v)
        cout << i << ' ';
    cout << '\n';

    // 删除v[1]到v[4]的元素，左闭右开[1, 4)
    v.erase(v.begin() + 1, v.begin() + 4);
    for(auto i: v)
        cout << i << ' ';
    cout << '\n';

    // 一键清空vector中的所有元素
    v.clear();

    // 如下可看出容器虽然清空了元素，但是被清空元素的内存并没有归还
    cout << "capacity:" << v.capacity() << '\n';
    // 额外内存可通过 shrink_to_fit() 调用返回给系统
    v.shrink_to_fit();
    cout << "capacity:" << v.capacity() << '\n';

    system("pause");
    return 0;
}