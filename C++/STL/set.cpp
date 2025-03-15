#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// 内部自动有序且不含重复元素的容器。
// 红黑树实现

int main()
{
    set<int> st;

    // 容器的初始化
    set<int> st1 = {1, 2, 3};
    set<int> st2(st1);
    vector<int> v = {10, 5, 20, 15, 10};
    set<int> st3(v.begin(), v.end());

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    st.insert(6);

    // set只能通过迭代器(iterator)访问：
    set<int>::iterator it;

    // 插入元素
    int item = -1;
    st.insert(item);

    // find(value)返回的是set中value所对应的迭代器，也就是value的指针（地址）。
    it = st.find(2); // 在set中查找2，返回其迭代器
    cout << *it << endl;

    // st.erase(it)，其中it为所需要删除元素的迭代器。时间复杂度为O(1)。可以结合find()函数来使用。
    st.erase(it);

    // st.erase(value)，value为所需要删除元素的值。其时间复杂度为O(logN)，N为set内的元素个数。
    st.erase(item);

    // st.erase(iteratorBegin , iteratorEnd)可以删除一个区间内的所有元素。

    // 容器元素的数量
    st.size();

    system("pause");
    return 0;
}