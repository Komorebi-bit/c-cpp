#include <iostream>

#define DEBUG

#define MAXSIZE 20

#define _for_(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;


int Prim(struct MGraph &);
void Dijkstra(struct MGraph &);

struct MGraph
{
    // int vertex[MAXSIZE];
    int edge[MAXSIZE][MAXSIZE];
    int vertexnum, edgenum;
};

int main()
{
    struct MGraph M;
    _for_(i, 1, MAXSIZE)
        _for_(j, 1, MAXSIZE)
            M.edge[i][j] = 0x3f3f3f3f;
    cin >> M.vertexnum >> M.edgenum;
    int a = 0, b = 0, c = 0;
    _for_(i,1,M.edgenum+1)
    {
        cin >> a >> b >> c;
        M.edge[a][b] = c;
        M.edge[b][a] = c;
    }

    cout << Prim(M) << '\n';
    Dijkstra(M);


    system("pause");
    return 0;
}

//普利姆算法
int Prim(struct MGraph& M)
{
    int n = M.vertexnum;
    int res = 0;
    int u[n + 1] = {0, 1};  // 加入到最小生成树结点，顶点1已加入最小生成树中
    int uu[n + 1] = {0};    // 0表示顶点（索引）未加入到最小生成树中
    uu[1] = 1;  // 顶点1已加入最小生成树中，所以赋值为1
    int t = 0;  // 候选点
    int min = 0x3f3f3f3f;  //侯选边
    int i = 0, k = n-1;
    while(k--)
    {
        i = 0;
        min = 0x3f3f3f3f;
        while(u[++i])
        {
            _for_(j,1,n+1)
                if(!uu[j] && M.edge[u[i]][j]<min)
                {
                    min = M.edge[u[i]][j];
                    t = j;
                }
        }
        u[i] = t;
        uu[t] = 1;
        res += min;
    }
#ifdef DEBUG
    _for_(i, 1, n + 1)
        cout<< u[i] << ' ';
    cout << '\n';
    _for_(i, 1, n + 1)
        cout<< uu[i] << ' ';
    cout << '\n';
#endif
    return res;
}

//迪杰斯特拉算法
void Dijkstra(struct MGraph& M)
{
    int n = M.vertexnum;
    int dist[n + 1];
    string path[n + 1]; //自动初始化""
    int u[n + 1] = {0, 1};  //
    int uu[n + 1] = {0,1};    //
    int min = 0x3f3f3f3f;
    int t = 0, i = 1, d = 0, k = n - 1;
    _for_(j, 1, n + 1) path[j] = "1";
    _for_(j, 1, n + 1) dist[j] = M.edge[j][i];

    while(k--)
    {
        _for_(j, 1, n + 1)
        {
            d = dist[u[i]] + M.edge[u[i]][j];
            if(!uu[j] && d <dist[j])
            {
                dist[j] = d;
                path[j] += "->";
                path[j] += u[i]+'0';
            }
        }
        min = 0x3f3f3f3f;
        _for_(j,1,n+1)
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
#ifdef DEBUG
    _for_(i, 1, n + 1) cout << u[i] << ' ';
    cout << endl;
    _for_(i, 2, n + 1) cout << "1->" << i << "最短距离: " << dist[i] << '\n';
    _for_(i, 1, n + 1) cout << path[i] << endl;
#endif

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
*/