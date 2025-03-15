#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // 默认大根堆, 即每次取出的元素是队列中的最大值
    priority_queue<int> pq;
    // 小根堆, 每次取出的元素是队列中的最小值
    //priority_queue<int, vector<int>, greater<int>> q;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    //访问队首元素 O(1)
    pq.top();
    //入队 O(logN)
    pq.push(4);
    //堆顶（队首）元素出队 O(logN)
    pq.pop();
    //队列元素个数 O(1)
    pq.size();
    //是否为空 O(1)
    pq.empty();
    //注意没有clear()！	不提供该方法
    //优先队列只能通过top()访问队首元素（优先级最高的元素）


    system("pause");
    return 0;
}