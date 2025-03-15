#include <iostream>
#include <queue>
#include <cstring>

#define piii pair<int, pair<int, int>>
#define pii pair<int, int>

using namespace std;

const int N = 10005;

priority_queue<piii, vector<piii>, greater<piii>> pq;

int p[N];

// void init(int[]);
int find(int);
int merge(int, int);
int kruskal(int);

int main()
{
    int n, m;
    int a, b, c;
    cin >> n >> m;
    // init(p);
    memset(p, -1, sizeof p);
    while (m--)
    {
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }
    int res = kruskal(n);
    cout << res << '\n';

    system("pause");
    return 0;
}

// void init(int arr[])
// {
//     for (int i = 0; i < N; i++)
//         arr[i] = -1;
// }

int find(int a)
{
    while (p[a] != -1)
        a = p[a];
    return a;
}

int merge(int a, int b)
{
    int r1 = find(a);
    int r2 = find(b);
    if (r1 == r2)
        return 0; // 不需要合并
    p[r1] = r2;
    p[a] = r2;
    if (b != r2)
        p[b] = r2;
    return 1;
}

int kruskal(int n)
{
    piii e;
    pii uv;
    int res = 0, flag = 0;
    int cnt = 0; // 加入的边数
    while (!pq.empty())
    {
        e = pq.top();
        uv = e.second;
        pq.pop();
        flag = merge(uv.first, uv.second);
        if (flag)
        {
            cnt++;
            cout << uv.first << " -> " << uv.second << "  #" << e.first << '\n';
            res += e.first;
        }
        if(cnt == n-1)
            break;
    }
    return res;
}
/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
8

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