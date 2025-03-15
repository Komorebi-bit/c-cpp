#include <iostream>
#include <queue>
#include <cstring>

// #define DEBUG

#define For(i, a, b) for (int i = (a); i < (b); i++)

const int N = 10005;
const int M = 200010;
const int INF = 0x3f3f3f3f;

int h[N];
int e[M];
int w[M];
int ne[M];
int idx = 0;

void init();
void insert(int, int, int);
int prim(int);

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    int a, b, c;
    cin >> n >> m;
    memset(h, -1, sizeof h); //初始化h[]
    while (m--)
    {
        cin >> a >> b >> c;
        insert(a, b, c);
    }

    int res = prim(n);
    cout << res << '\n';

    system("pause");
    return 0;
}

void insert(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;

    e[idx] = a;
    w[idx] = c;
    ne[idx] = h[b];
    h[b] = idx++;
}

int prim(int n)
{
    int res = 0;
    int b;
    int i;
    int marked[n+1] = {0};
    pii t;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();

        b = t.second;
        if (marked[b])
            continue;
        marked[b] = 1;

#ifdef DEBUG
        cout<< " -> " << b << "  #" << t.first << '\n';
        // 若打印边的信息，使用piii
#endif

        res += t.first;
        
        for (i = h[b]; i != -1; i = ne[i]) //~i
            pq.push({w[i], e[i]});
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