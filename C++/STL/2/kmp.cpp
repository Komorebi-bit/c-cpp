#include <iostream>

using namespace std;

char s[100000]; // 主串
char p[10000];  // 模式串
int n, m;

int kmp(int[]);

int main()
{
    cin >> n >> (s + 1) >> m >> (p + 1); // 下标从1开始
    int next[m + 1];
    int res = kmp(next);
    cout << res << '\n';

    system("pause");
    return 0;
}

int kmp(int next[])
{
    next[1] = 0;
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && p[i] != p[j + 1])
            j = next[j];
        if (p[i] == p[j + 1])
            j++;
        next[i] = j;
    }
    for (int i = 1; i <= m; i++)
        cout << next[i] << ' ';
    cout << '\n';

    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1])
            j = next[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m)
        {
            // 成功后的逻辑
            return i - j + 1;
            // 回退继续尝试下次匹配
            j = next[j];
        }
    }
    return -1;
}

// void construct_next(int next[])
// {

// }
/*
12
AABABADDABAC
3
ABA


11
ababaababcb
5
ababc
*/