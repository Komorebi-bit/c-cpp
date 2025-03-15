#include <iostream>

const int N = 10005;

// h[N]存储堆中的值，h[1]是堆顶，x的左儿子是2x，右儿子是2x + 1，下标从1开始
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N];
int size;

void init();
void down(int);
void up(int);
void heap_swap(int, int);

using namespace std;

// 小根堆

int main()
{
    int x = 3, y = 6, k = 8;
    size = 10;
    for (int i = 1, j = size; i <= size; i++)
        h[i] = j--;
    init();
    for (int i = 1; i <= size;i++)
        cout << h[i] << ' ';
    cout << '\n';

    // 查询最小值
    cout << h[1] << '\n';

    // 删除堆顶
    h[1] = h[size--];
    down(1);
    // 插入x
    h[++size] = x;
    up(size);
    // 删除位置k上的元素
    h[k] = h[size--];
    down(k);
    up(k);
    // 修改位置k上的元素
    h[k] = y;
    down(k);
    up(k);

    system("pause");
    return 0;
}

void init()
{
    for (int i = size / 2; i; i--)
        down(i);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (t != u)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

void heap_swap(int a, int b)
{
    swap(h[a], h[b]);
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
}

