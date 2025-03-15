#include <iostream>
using namespace std;

template <typename T>
struct TNode
{
    T data;
    TNode<T> *firstChild, *rightSib;
};

template <typename T>
class Tree
{
public:
    Tree() { root = creat(); }
    ~Tree() { Release(root); }
    void PreOrder() { PreOrder(root); }
    void PostOrder() { PostOrder(root); }

private:
    TNode<T> *creat();
    void Release(TNode<T> *t);
    void PreOrder(TNode<T> *t);
    void PostOrder(TNode<T> *t);
    TNode<T> *root;
};

template <typename T>
TNode<T> *Tree<T>::creat()
{
    TNode<T> *t;
    char ch;
    cin >> ch;
    if (ch == '#')
        t = nullptr;
    else
    {
        t = new TNode<T>;
        t->data = ch;
        t->firstChild = creat();
        t->rightSib = creat();
    }
    return t;
}

template <typename T>
void Tree<T>::Release(TNode<T> *t)
{
    if (t == nullptr)
        return;
    Release(t->firstChild);
    Release(t->rightSib);
    delete t;
}

template <typename T>
void Tree<T>::PreOrder(TNode<T> *t)
{
    if (t == nullptr)
        return;
    cout << t->data << '\t';
    PreOrder(t->firstChild);
    PreOrder(t->rightSib);
}

template <typename T>
void Tree<T>::PostOrder(TNode<T> *t)
{
    if (t == nullptr)
        return;
    PostOrder(t->firstChild);
    cout << t->data << '\t';
    PostOrder(t->rightSib);
}

int main()
{
    cout << "输入要创建的二叉树的元素，空用英文'#'来表示！！！" << endl;
    cout << "例如: 1 2 5 8 # # 6 # # 3 7 # # 4 # # #" << endl;
    Tree<char> T;
    cout << "前序遍历序列:" << endl;
    T.PreOrder();
    cout << endl;
    cout << "后序遍历序列:" << endl;
    T.PostOrder();
    cout << endl;

    system("pause");
    return 0;
}