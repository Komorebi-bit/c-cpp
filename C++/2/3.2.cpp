#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int **f(int n);
    int **p = f(n);
    int **q = f(n);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cin >> p[i][j];
    void transpostion(int ,int **, int **);
    transpostion(n,p, q);
    void show(int ,int **);
    show(n, q);
    system("pause");
    return 0;
}
int **f(int n)
{
    int **p = new int *[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = new int[n];
    }
    return p;
}
void transpostion(int n,int **p, int **q)
{
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
        {
            q[j][i] = p[i][j];
        }
}
void show(int n, int **q)
{
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
            cout << q[i][j]<<"  ";
        cout << endl;
    }
}