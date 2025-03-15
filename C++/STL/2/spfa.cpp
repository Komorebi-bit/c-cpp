#include <cstring>
#include <iostream>
#include <queue>

#define DEBUG

const int N = 10005;
const int M = 200010;

int h[N];
int e[M];
int w[M];
int ne[M];
int idx = 0;

void insert(int, int, int);
void spfa(int,int);

using namespace std;

int main()
{
    int n, m;
    int a, b, c;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        cin >> a >> b >> c;
        insert(a, b, c);
    }

    spfa(1,n);

    system("pause");
    return 0;
}

void spfa(int start,int n)
{
    int dis[N];
    int mk[N];
    queue<int> q;
    int b, c, i, d;

    memset(dis, 0x3f, sizeof dis);
    memset(mk, 0, sizeof mk);

    dis[start] = 0;
    q.push(start);
    mk[start] = 1;
    while (!q.empty())
    {
        b = q.front();
        q.pop();
        mk[b] = 0;
        for (i = h[b]; ~i; i = ne[i]) //i=-1时跳出循环，-1=0XFFFFFFFF，按位取反 0x00000000，即当i=-1时，~i=0，为假，退出循环
        {
            c = e[i];
            d = dis[b] + w[i];
            if(dis[c]>d)
            {
                dis[c] = d;
                if(!mk[c])
                {
                    q.push(c);
                    mk[c] = 1;
                }
            }
        }
    }
#ifdef DEBUG
    for (int i = 1; i <= n;i++)
        cout << dis[i] << ' ';
    cout << '\n';
#endif
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

/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
dist[] = 0 4 5 7

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

dist[] = 0 4 7 5 1 2
*/