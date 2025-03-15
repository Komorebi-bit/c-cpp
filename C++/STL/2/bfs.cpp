#include <cstring>
#include <iostream>
#include <queue>

const int N = 10005;
const int M = 200010;

int h[N], e[M], w[M], ne[M];
int idx = 0;
int n;
int mk[N];

void insert(int, int, int);
void bfs(int);

using namespace std;

int main()
{
    int m, a, b, c;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(mk, 0, sizeof mk);
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        insert(a, b, c);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
        cout << mk[i] << ' ';
    cout << '\n';
    system("pause");
    return 0;
}

void bfs(int a)
{
    queue<int> q;
    mk[a]=1;
    q.push(a);
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        for (int i = h[a]; ~i; i = ne[i])
        {
            a = e[i];
            if (!mk[a])
            {
                mk[a]=1;
                q.push(a);
            }
        }
    }
}

void insert(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    
    w[idx] = c;
    e[idx] = a;
    ne[idx] = h[b];
    h[b] = idx++;
}