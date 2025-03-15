#include <cstring>
#include <iostream>
#include <queue> //优先队列是个好东西
#include <utility>
#include <cstring>

#define DEBUG

typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int N = 10005;
const int M = 200010;

using namespace std;

int h[N];    // 存储链表头 N_MAXSIZE个单链表表头
int w[M];    // 边的权值
int e[M];    // 存储结点的值
int ne[M];   // 存储结点的next指针
int idx = 0; // 当前结点

int dist[N]; // 最短距离

int n, m;

// void init(int[]);
void insert(int, int, int);
void dijkstra(int, int); //不允许有负权值的边

// dijstra算法、数组模拟邻接表，优先队列，二元组，
// 堆优化版

int main()
{
    scanf("%d%d", &n, &m);
    int i = m, u, v, c;
    memset(h, -1, sizeof h);
    while (i--)
    {
        scanf("%d%d%d", &u, &v, &c);
        insert(u, v, c);
    }

    dijkstra(1, n);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << '\n';

    system("pause");
    return 0;
}

void dijkstra(int start, int n)
{
    memset(dist, 0x3f, sizeof dist); // 初始化
    dist[start] = 0;
    int marked[n + 1] = {0}; // 标记是否已找到最短路径
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pii t;
    int b, c; // start->b->c
    int i;    // 指针

    pq.push({0, start});
    while (!pq.empty())
    {
        t = pq.top(); // 出队，检查是否被标记，
        pq.pop();

        b = t.second; // b = pq.top().second;

        if (marked[b])
            continue;
        marked[b] = 1; // 所有的结点都是先出队后标记

        for (i = h[b]; i != -1; i = ne[i]) // 遍历与此结点相连的所有的边，
        {                                  // i != -1可以写成 ~i
            c = e[i];
            if (!marked[c] && dist[c] > dist[b] + w[i]) // 已经被标记的点，就不要再参与比较了，参与也不影响结果
            {
                dist[c] = dist[b] + w[i];
                pq.push({dist[c], c});
            }
        }
    }
}

void insert(int u, int v, int c) // 链表的插入操作
{
    e[idx] = v;
    w[idx] = c;
    ne[idx] = h[u];
    h[u] = idx++;

    e[idx] = u;
    w[idx] = c;
    ne[idx] = h[v];
    h[v] = idx++;
}

// void init(int h[]) // 头指针初始化为-1
// {
//     int i = N - 1;
//     while (i--)
//         h[i] = -1;
// }

/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
dist[] = 0 4 5 7

6 10
1 2 4
1 5 1
1 6 2
2 3 6
2 6 3
3 4 6
3 6 5
4 5 4
4 6 5
5 6 3

dist[] = 0 4 7 5 1 2
*/