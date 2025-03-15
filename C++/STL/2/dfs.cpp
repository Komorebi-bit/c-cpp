#include <cstring>
#include <iostream>

const int N = 10005;
const int M = 200010;

int h[N], e[M], w[M], ne[M];
int idx = 0;
int n;
int mk[N];

void insert(int, int, int);
void dfs(int);

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

    dfs(1);
    for(int i=1;i<=n;i++)
        cout << mk[i] << ' ';
    cout << '\n';
    system("pause");
    return 0;
}

void dfs(int a)
{
    mk[a] = 1;
    for (int i = h[a]; ~i; i = ne[i])
        if (!mk[e[i]])
            dfs(e[i]);
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