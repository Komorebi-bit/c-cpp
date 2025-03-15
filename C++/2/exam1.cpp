#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a, n;
    cin >> a >> n;
    int **p = new int *[n];
    for (int i = 0; i < n;i++)
    {
        p[i] = new int[n];
    }
    void cube(int a, int n, int** p);
    cube(a, n, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            cout <<setw(4)<< p[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    system("pause");
    return 0;
}
void cube(int a,int n,int** p)
{
    int k = a, x = 0, y = 0;
    int i=0, j=0;
    while(k<a+n*n)
    {
        x = 0, y = j;
        while(x<i)
            p[x++][y] = k++;
        while(y>=0)
        {
            p[x][y--] = k++;
        }
        i++,j++;
    }
}