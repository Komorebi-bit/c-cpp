#include <iostream>

#define DEBUG

/* 最烂解 ；邻接矩阵实现 */


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

#define MAXSIZE 10005

#define _for_(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int Dijkstra(struct MGraph &); //非 迪杰斯特拉算法

struct MGraph
{
    // int vertex[MAXSIZE];
    // int edge[MAXSIZE][MAXSIZE];
    int **edge;
    int vertexnum, edgenum;
};

int main()
{
    int **edge = (int **)malloc(MAXSIZE * sizeof(int *));
    _for_(i, 0, MAXSIZE) edge[i] = (int *)malloc(MAXSIZE * sizeof(int));
    struct MGraph M;
    M.edge = edge;

    _for_(i, 1, MAXSIZE)
        _for_(j, 1, MAXSIZE)
            M.edge[i][j] = 0x3f3f3f3f;

    cin >> M.vertexnum >> M.edgenum;
    int a = 0, b = 0, c = 0;
    _for_(i,1,M.edgenum+1)
    {
        cin >> a >> b >> c;
        if(c<M.edge[a][b])
        {
            M.edge[a][b] = c;
            M.edge[b][a] = c;
        }
    }

    int res = Dijkstra(M);
    cout << res << endl;


    for(int i=0;i<MAXSIZE;i++)
    {
        free(edge[i]);
    }
    free(edge);

    system("pause");
    return 0;
}

//改造 迪杰斯特拉算法
int Dijkstra(struct MGraph& M)
{
    int n = M.vertexnum;
    int dist[n + 1];
    string path[n + 1]; //自动初始化""
    int u[n + 1] = {0, 1};  //
    int uu[n + 1] = {0,1};    //
    int min = 0x3f3f3f3f;
    int t = 0, i = 1, d = 0, k = n - 1;
    int cost[n + 1] = {0};
    _for_(j, 1, n + 1) path[j] = "1";
    _for_(j, 1, n + 1) dist[j] = M.edge[i][j];

    while(k--)
    {
        _for_(j, 1, n + 1)
        {
            d = dist[u[i]] + M.edge[u[i]][j];
            // if(!uu[j] && d == dist[j])
            // {
            //     if(M.edge[u[i]][j] <= dist[j])
            //         cost[j] = M.edge[u[i]][j];
            // }
            if(!uu[j] && d < dist[j])
            {
                dist[j] = d;
                path[j] += "->";
                path[j] += u[i]+'0';
            }
        }
        _for_(j,1,n+1)
        {
            d = dist[u[i]] + M.edge[u[i]][j];
            if(!uu[j] && d == dist[j])
            {
                if(M.edge[u[i]][j] <= dist[j])
                    cost[j] = M.edge[u[i]][j];
            }
        }
        min = 0x3f3f3f3f;
        _for_(j,1,n+1)  //dist[]选择距离最小的边，将其对应的点放入集合u中，
        {
            if(!uu[j] && dist[j]<min)
            {
                min = dist[j];
                t = j;
            }
        }
        u[++i] = t;
        uu[t] = 1;
        path[t] += "->";
        path[t] += t + '0';
    }

    _for_(i, 2, n + 1) if (!cost[i]) cost[i] = dist[i];

#ifdef DEBUG
    _for_(i, 1, n + 1) cout << u[i] << ' ';
    cout << endl;
    _for_(i, 2, n + 1) cout << "1->" << i << "最短距离: " << dist[i] << '\n';
    _for_(i, 1, n + 1) cout << path[i] << endl;
    _for_(i, 1, n + 1) cout << cost[i] << ' ';
    cout << endl;
#endif

    int res = 0;
    _for_(i, 2, n + 1) res += cost[i];
    return res;
}



/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2

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
15

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
*/