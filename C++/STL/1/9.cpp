#include <iostream>
#include <vector>

/* 次优解  邻接表（vector）实现*/

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
#define MAXSIZE 10002

using namespace std;

int Dijkstra(vector<struct edgeNode>[], int);

struct edgeNode
{
    int v;
    int c;
    edgeNode(int vv=0,int cc=0)
    {
        v = vv;
        c = cc;
    }
};

int main()
{
    vector<struct edgeNode> G[MAXSIZE]; //无向图  类似于邻接表
    int n = 0;  // 定点数
    int m = 0;  // 边数
    cin >> n >> m;
    int i = m, u, v, c;
    while(i--)
    {
        cin >> u >> v >> c;
        G[u].push_back(edgeNode(v, c));
        G[v].push_back(edgeNode(u, c));
    }

    int res = Dijkstra(G, n);
    cout << res << '\n';
    system("pause");
    return 0;
}

int Dijkstra(vector<struct edgeNode> G[], int n)
{
    int dist[n + 1];
    int marked[n + 1] = {0, 1};
    int stack[n] = {1};
    int top = 0; //指向栈顶元素
    for (int i = 0; i < n + 1; i++)
        dist[i] = 0x3f3f3f3f;  //初始化

    for(auto e: G[1])
        if(dist[e.v] > e.c)
            dist[e.v] = e.c;

    int min = 0x3f3f3f3f;
    int dis = 1;
    int nn = n - 1;
    while(nn--)
    {
        min = 0x3f3f3f3f;
        for(auto e: G[dis])
        {
            if(dist[dis] + e.c < dist[e.v])
                dist[e.v] = dist[dis] + e.c;
        }
        for (int i = 1; i < n + 1; i++)
            if(!marked[i] && dist[i]<min)
            {
                min = dist[i];
                dis = i;
            }
        marked[dis] = 1;
        stack[++top] = dis;
    }

    // for (int i = 0; i < n;i++)
    //     cout << stack[i] << ' ';
    // cout << '\n';
    // for (int i = 2; i < n + 1; i++)
    //     cout << "1->" << i << "最短距离: " << dist[i] << '\n';

    //求cost,非dijkstra算法
    int cost[n + 1] = {0};
    for (int i = 2; i < n + 1; i++)
    {
        for(auto e:G[i])
            if(dist[i] == dist[e.v] + e.c && (!cost[i] || e.c < cost[i]))
                cost[i] = e.c;
        if(!cost[i])
            cost[i] = dist[i];
    }
    int res = 0;
    for (int i = 2; i < n + 1; i++)
    {
        res += cost[i];
        // cout << cost[i] << ' ';
    }
    // cout << '\n';
    return res;
}

/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
加入集合的先后: 1 2 3 4
1->2最短距离: 4
1->3最短距离: 5
1->4最短距离: 7
cost[] = 4 5 2
11

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
加入集合的先后: 1 5 6 2 4 3
1->2最短距离: 4
1->3最短距离: 7
1->4最短距离: 5
1->5最短距离: 1
1->6最短距离: 2
cost[] = 4 5 4 1 2
16

10 50
4 6 8
5 10 14
10 5 3
5 9 10
5 2 9
4 5 2
5 8 10
6 3 5
2 3 3
8 9 16
9 4 1
6 5 16
1 2 3
4 6 8
1 3 16
10 3 10
9 4 11
4 5 15
9 10 3
4 10 20
5 3 13
3 10 15
8 6 6
2 3 19
4 7 13
2 3 9
1 4 2
5 6 12
6 3 3
4 2 8
3 9 8
2 6 3
1 2 4
8 9 4
6 7 13
7 5 10
4 8 4
3 8 2
2 6 9
8 2 6
1 4 4
10 6 8
3 10 18
10 9 16
10 2 3
4 6 5
6 8 15
7 4 19
7 1 12
10 9 3
33
*/