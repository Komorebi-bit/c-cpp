#include<iostream>
using namespace std;

const int MaxSize = 10;
int visited[MaxSize] = {0};

template<typename T>
struct EdgeNode
{
    int adjvex;
    EdgeNode<T> *next;
};
template<typename T>
struct VertexNode
{
    T vertex;
    EdgeNode<T> *firstEdge;
};

template<typename T>
class ALGraph
{
    public:
        ALGraph(T a[], int n, int e);
        ~ALGraph();
        void DFTraverse(int v);
        void BFTraverse(int v);
    private:
        VertexNode<T> adjlist[MaxSize];
        int vertexNum, edgeNum;
};
template<typename T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
    int i, j, k;
    vertexNum = n;
    edgeNum = e;
    EdgeNode<T> *s = nullptr;
    for (i = 0; i < vertexNum;i++){
        adjlist[i].vertex = a[i];
        adjlist[i].firstEdge = nullptr;
    }
    for (k = 0; k < edgeNum;k++){
        cin >> i >> j;
        s = new EdgeNode<T>;
        s->adjvex = j;
        s->next = adjlist[i].firstEdge;
        adjlist[i].firstEdge = s;
    }
}
template<typename T>
ALGraph<T>::~ALGraph()
{
    EdgeNode<T> *p = nullptr, *q = nullptr;
    for (int i = 0; i < vertexNum;i++){
        p = q = adjlist[i].firstEdge;
        while(q!=nullptr){
            p = p->next;
            delete q;
            q = p;
        }
    }
}
template<typename T>
void ALGraph<T>::DFTraverse(int v)
{
    int j;
    EdgeNode<T> *p = nullptr;
    cout << adjlist[v].vertex <<" ";
    visited[v] = 1;
    p = adjlist[v].firstEdge;
    while(p!=nullptr){
        j = p->adjvex;
        if(visited[j]==0)
            DFTraverse(j);
        p = p->next;
    }
}
template<typename T>
void ALGraph<T>::BFTraverse(int v)
{
    int w,j,Q[MaxSize];
    EdgeNode<T> *p = nullptr;
    int front = -1, rear = -1;
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    Q[++rear] = v;
    while(rear!=front)
    {
        w = Q[++front];
        p = adjlist[w].firstEdge;
        while(p!=nullptr){
            j = p->adjvex;
            if(visited[j]==0){
                cout << adjlist[j].vertex << " ";
                visited[j] = 1;
                Q[++rear] = j;
            }
            p = p->next;
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
    char ch[] = {'A', 'B', 'C', 'D', 'E'};
    ALGraph<char> ALG(ch, 5, 6);
    for (int i = 0; i < MaxSize;i++)
        visited[i] = 0;
    cout << "深度优先遍历:" << endl;
    ALG.DFTraverse(0);
    cout << endl;
    for (int i = 0; i < MaxSize;i++)
        visited[i] = 0;
    cout << "广度优先遍历:" << endl;
    ALG.BFTraverse(0);
    cout << endl;
    system("pause");
    return 0;
}