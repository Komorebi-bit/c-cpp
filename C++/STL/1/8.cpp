#include <iostream>
#include <unordered_map>

#define DEBUG

/* 次次优解  邻接表（map、哈希表）实现 */

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

// struct edgeNode
// {
//     int info;
//     int adjvex;
//     struct edgeNode *next;
// };

#define for_(i, a, b) for (int i = (a); i < (b); i++)

#define MAXSIZE 10002

int Dijkstra(struct ALGraph &); //非 迪杰斯特拉算法

using namespace std;


struct vertexNode
{
    int vertex;
    unordered_map<int, int> edge; //用map（哈希表）作为边表
};

struct ALGraph
{
    int vertexnum, edgenum;
    struct vertexNode vertexes[MAXSIZE];
};



int main()
{
    struct ALGraph AG;
    cin >> AG.vertexnum >> AG.edgenum;
    int u, v, weight;
    struct vertexNode *p;
    for_(i,0,AG.edgenum)
    {
        cin >> u >> v >> weight;
        p = &AG.vertexes[u];
        if(p->edge.find(v) == p->edge.end() || weight< p->edge[v])
        {
            p->edge[v] = weight;
            AG.vertexes[v].edge[u] = weight;
        }

    }

    int res = Dijkstra(AG);
    cout << res << endl;

    // cout << "--------------" << '\n';
    // for_(i,1,AG.vertexnum+1)
    // {
    //     for(auto mp: AG.vertexes[i].edge)
    //         cout << i << ' ' << mp.first << ' ' << mp.second << endl;
    // }

    system("pause");
    return 0;
}

//改造 迪杰斯特拉算法
int Dijkstra(struct ALGraph& AG)
{
    int n = AG.vertexnum;
    int dist[n + 1];

    int u[n + 1] = {0, 1};  //
    int uu[n + 1] = {0,1};    //
    int min = 0x3f3f3f3f;
    int t = 0, i = 1, d = 0, k = n - 1;
    int cost[n + 1] = {0};


    for_(j, 1, n + 1) dist[j] = 0x3f3f3f3f;

    for(auto mp: AG.vertexes[1].edge)
    {
        dist[mp.first] = mp.second;
    }

    while(k--)
    {
        for(auto mp: AG.vertexes[u[i]].edge)
        {
            d = dist[u[i]]+mp.second;
            if(!uu[mp.first] && d < dist[mp.first])
                    dist[mp.first] = d;
        }

        for(auto mp: AG.vertexes[u[i]].edge)
        {
            d = dist[u[i]]+mp.second;
            if(!uu[mp.first] && d == dist[mp.first])
            {
                    if(mp.second <= dist[mp.first])
                        cost[mp.first] = mp.second;
            }
        }
        min = 0x3f3f3f3f;
        for_(j, 1, n + 1) // dist[]选择距离最小的边，将其对应的点放入集合u中，
        {
            if(!uu[j] && dist[j]<min)
            {
                min = dist[j];
                t = j;
            }
        }
        u[++i] = t;
        uu[t] = 1;
    }

    for_(i, 2, n + 1) if (!cost[i]) cost[i] = dist[i];

#ifdef DEBUG
    for_(i, 1, n + 1) cout << u[i] << ' ';
    cout << endl;
    for_(i, 2, n + 1) cout << "1->" << i << "最短距离: " << dist[i] << '\n';
    // _for_(i, 1, n + 1) cout << path[i] << endl;
    for_(i, 1, n + 1) cout << cost[i] << ' ';
    cout << endl;
#endif

    int res = 0;
    for_(i, 2, n + 1) res += cost[i];
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