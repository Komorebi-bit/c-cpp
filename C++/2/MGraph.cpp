#include<iostream>
using namespace std;

const int MaxSize = 10;
int visited[MaxSize] = {0};

template<typename T>
class MGraph
{
    public:
        MGraph(T a[], int n, int e);
        ~MGraph(){}
        void DFTraverse(int v);
        void BFTraverse(int v);
    private:
        T vertex[MaxSize];
        int edge[MaxSize][MaxSize];
        int vertexNum, edgeNum;
};

template<typename T>
MGraph<T>::MGraph(T a[], int n, int e)
{
    int i, j, k;
    vertexNum = n;
    edgeNum = e;
    for (i=0; i < vertexNum;i++)
        vertex[i] = a[i];

    for (i=0; i < edgeNum;i++)
        for (j = 0; j < edgeNum;j++)
            edge[i][j] = 0;
    cout << "输入边依附的两个顶点的编号:" << endl;
    for (k = 0; k < edgeNum;k++){
        cin >> i >> j;
        edge[i][j] = 1;
        edge[j][i] = 1;
    }
}
template<typename T>
void MGraph<T>::DFTraverse(int v)
{
    cout << vertex[v]<<" ";
    visited[v] = 1;
    for (int i = 0; i < vertexNum;i++){
        if(edge[v][i]==1 && visited[i]==0)
            DFTraverse(i);
    }
}
template<typename T>
void MGraph<T>::BFTraverse(int v)
{
    int w;
    int Q[MaxSize];
    int front = -1, rear = -1;
    cout << vertex[v]<<" ";
    visited[v] = 1;
    Q[++rear] = v;
    while(rear!=front)
    {
        w = Q[++front];
        for (int i = 0; i < vertexNum;i++){
            if (edge[w][i] == 1 && visited[i]==0){
                cout << vertex[i]<<" ";
                visited[i] = 1;
                Q[++rear] = i;
            }
        }
    }
}
/*
0 1
1 2
2 3
3 4
0 4
1 4
*/
int main()
{
    char ch[] = {'a', 'b', 'c', 'd', 'e'};
    MGraph<char> MG(ch, 5, 6);
    for (int i = 0; i < MaxSize;i++)
        visited[i] = 0;
    cout << "深度优先遍历:" << endl;
    MG.DFTraverse(0);
    cout << endl;
    for (int i = 0; i < MaxSize;i++)
        visited[i] = 0;
    cout << "广度优先遍历:" << endl;
    MG.BFTraverse(2);
    cout << endl;
    system("pause");
    return 0;
}