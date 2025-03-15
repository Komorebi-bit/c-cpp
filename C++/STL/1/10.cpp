#include <iostream>
#include <queue>  //优先队列是个好东西
#include <utility>

#define DEBUG

/* 最优解  邻接表（数组模拟），优先队列实现 */

/*
G国国王来中国参观后，被中国的高速铁路深深的震撼，决定为自己的国家也建设一个高速铁路系统。
建设高速铁路投入非常大，为了节约建设成本，G国国王决定不新建铁路，而是将已有的铁路改造成高速铁路。
现在，请你为G国国王提供一个方案，将现有的一部分铁路改造成高速铁路，
使得任何两个城市间都可以通过高速铁路到达，而且从所有城市乘坐高速铁路到首都的最短路程和原来一样长。
请你告诉G国国王在这些条件下最少要改造多长的铁路。

输入格式
输入的第一行包含两个整数 n,m，分别表示G国城市的数量和城市间铁路的数量。所有的城市由1到n编号，首都为1号。
接下来 m行，每行三个整数 a,b,c，表示城市a和城市b之间有一条长度为c的双向铁路。
这条铁路不会经过a和b以外的城市。

输出格式
输出一行，表示在满足条件的情况下最少要改造的铁路长度。

数据范围
对于20%的评测用例，1≤n≤10，1≤m≤50；
对于50%的评测用例，1≤n≤100，1≤m≤5000；
对于80%的评测用例，1≤n≤1000，1≤m≤50000；
对于100%的评测用例，1≤n≤10000，1≤m≤100000，
1≤a,b≤n，1≤c≤1000。
输入保证每个城市都可以通过铁路达到首都。两个城市之间可能存在不止一条铁路。
*/

#define pii pair<int,int>

#define N_MAXSIZE 10005
#define M_MAXSIZE 200010

using namespace std;

int h[N_MAXSIZE];  //存储链表头 N_MAXSIZE个单链表表头
int w[M_MAXSIZE];  //边的权值
int e[M_MAXSIZE];  //存储结点的值
int ne[M_MAXSIZE]; //存储结点的next指针
int idx = 0;       //当前结点

int n, m;

void init(int[]);
void insert(int, int, int);
int Dijkstra();

//dijstra算法、数组模拟邻接表，优先队列，二元组，

int main()
{
    scanf("%d%d", &n, &m);
    int i = m, u, v, c;
    init(h);
    while(i--)
    {
        scanf("%d%d%d", &u, &v, &c);
        insert(u, v, c);
    }
    // for (int i = 0; i < m + m; i++)
    //     cout << e[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < m + m; i++)
    //     cout << w[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < m + m; i++)
    //     cout << ne[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i < n+1; i++)
    //     cout << h[i] << ' ';
    // cout << '\n';

    int res = Dijkstra();
    cout << res << '\n';
    system("pause");
    return 0;
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

void init(int h[]) // 头指针初始化为-1
{
    int i = N_MAXSIZE - 1;
    while(i--)
        h[i] = -1;
}

int Dijkstra()
{
    int dist[n + 1];   // 保存最短路径长度
    int marked[n + 1] = {0, 1};   // 标记i是否并入集合U（是否已选出来，是否已找到最短路径）
    int stack[n] = {1};  // 并入集合U的结点入栈
    int top = 0;  // 指向栈顶元素
    priority_queue<pii, vector<pii>, greater<pii>> pq;  //最小值在栈顶

    for (int i = 0; i < n + 1; i++)
        dist[i] = 0x3f3f3f3f;  //初始化dist[]
    dist[1] = 0;

    int ii;  // 指针
    int id = 1; // 当前访问的结点
    int nn = n - 1;

    while(nn--)  //很抽象哈
    {
        ii = h[id]; // 暂存当前访问的单链表的头结点
        while(ii!=-1) //-1表示此单链表访问完了
        {
            if(dist[id] + w[ii] < dist[e[ii]]) //从1到1的距离+从1到2的距离 是否小于 从1到2的距离（注意dist[]初始化为无穷大）
            {                                  //从结点1到结点id的距离+从结点id到结点e[ii]的距离 是否小于 从结点1到结点e[ii]的距离
                dist[e[ii]] = dist[id] + w[ii];
                pq.push({dist[e[ii]], e[ii]});
            }
            ii = ne[ii]; //指针指向结点id的下一个临接结点
        }

        pii ev;  //出栈并检查该结点是否被访问过，未被访问过结束循环
        for(ev = pq.top(),pq.pop(); marked[ev.second]; ev = pq.top(),pq.pop());
        id = ev.second;
        marked[ev.second] = 1; //标记
        stack[++top] = ev.second;  //入栈,加入U
    }

#ifdef DEBUG
    for (int i = 0; i < n;i++)
        cout << stack[i] << ' ';
    cout << '\n';
    for (int i = 2; i < n + 1; i++)
        cout << "1->" << i << "最短距离: " << dist[i] << '\n';
#endif

    // 求cost,非dijkstra算法
    int cost[n + 1] = {0};
    int res = 0;
    for (int i = 2; i < n + 1; i++)
    {
        ii = h[i];
        while (ii != -1)
        {
            if(dist[i] == dist[e[ii]] + w[ii] && (!cost[i] || w[ii] < cost[i]))
                cost[i] = w[ii];
            ii = ne[ii];
        }
        if (!cost[i])
            cost[i] = dist[i];
        res += cost[i];
    }

#ifdef DEBUG
    for (int i = 2; i < n + 1; i++)
        cout << cost[i] << ' ';
    cout << '\n';
#endif

    return res;
}
/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
*/