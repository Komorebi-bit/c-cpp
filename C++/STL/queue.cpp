#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    //返回队首元素O(1)
    q.front();
    // 返回队尾元素O(1)
    q.back();
    // 入队 尾部添加一个元素element O(1)
    int e = -1;
    q.push(e);
    //出队 删除第一个元素 O(1)
    q.pop();
    //返回队列中元素个数，返回值类型unsigned int O(1)
    q.size();
    //判断是否为空，队列为空，返回true O(1)
    q.empty();

    system("pause");
    return 0;
}
