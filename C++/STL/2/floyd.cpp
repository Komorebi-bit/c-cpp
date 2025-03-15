#include <iostream>

using namespace std;

#define N 1000
#define INF 0x3f3f3f3f

// 距离  邻接矩阵
int d[N][N];

// 允许有带负权值的边，但不允许有包含带负权值的边组成的回路

int main()
{
    int n, m;
    int a, b, c;
    cin >> n >> m;
    // 初始化
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                d[i][j] = INF;
    // 输入
    while (m--)
    {
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }
    // 使用
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[j][k];

    system("pause");
    return 0;
}
