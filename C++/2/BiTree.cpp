#include<iostream>
using namespace std;

template<typename T>
struct BiNode
{
    T data;
    BiNode<T> *lchild, *rchild;
};

template<typename T>
class BiTree
{
    public:
        BiTree()
        {
            root = Creat();
            leafcount = 0;
        }
        ~BiTree() { Release(root); }
        void PreOrder() { PreOrder(root); }
        void InOeder() { InOrder(root); }
        void PostOrder() { PostOrder(root); }
        void LevelOrder();
        int LeafNum()
        {
            LeafNum(root);
            return leafcount;
        }

    private:
        BiNode<T> *Creat();
        void Release(BiNode<T> *bt);
        void PreOrder(BiNode<T> *bt);
        void InOrder(BiNode<T> *bt);
        void PostOrder(BiNode<T> *bt);
        void LeafNum(BiNode<T> *bt);
        BiNode<T> *root;
        //叶子数
        int leafcount;
};

template<typename T>
BiNode<T>* BiTree<T>::Creat()
{
    BiNode<T> *bt;
    char ch;
    cin >> ch;
    if('#'==ch)
        bt = nullptr;
    else{
        bt = new BiNode<T>;
        bt->data = ch;
        bt->lchild = Creat();
        bt->rchild = Creat();
    }
    return bt;
}

template<typename T>
void BiTree<T>::Release(BiNode<T>* bt)
{
    if(bt == nullptr)
        return;
    else{
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

template <typename T>
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
    if(bt == nullptr)
        return;
    else{
        cout << bt->data << '\t';
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

template<typename T>
void BiTree<T>::InOrder(BiNode<T> *bt)
{
    if(bt == nullptr)
        return;
    else{
        InOrder(bt->lchild);
        cout << bt->data << '\t';
        InOrder(bt->rchild);
    }
}

template<typename T>
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
    if(bt == nullptr)
        return;
    else{
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout << bt->data << '\t';
    }
}

template<typename T>
void BiTree<T>::LevelOrder()
{
    struct BiNode<T> *Q[100], *q = nullptr;
    int front = -1, rear = -1;
    if(root = nullptr)
        return;
    Q[++rear] = root;
    while(front != rear)
    {
        q = Q[++front];
        cout << q->data << '\t';
        if(q->lchild != nullptr)
            Q[++rear] = q->lchild;
        if(q->rchild != nullptr)
            Q[++rear] = q->rchild;
    }
}

template<typename T>
void BiTree<T>::LeafNum(BiNode<T>* bt)
{
    if(bt == nullptr)
        return;
    else{
        LeafNum(bt->lchild);
        LeafNum(bt->rchild);
        if(bt->lchild==nullptr && bt->rchild==nullptr)
            leafcount++;
    }
}

int main()
{
    cout << "输入要创建的二叉树的元素，空用英文'#'来表示！！！" << endl;
    cout << "例如: 1 2 3 4 # # 5 # # 6 # # 7 8 # 9 # # #" << endl;
    BiTree<char> T;
    cout << "前序遍历序列:" << endl;
    T.PreOrder();
    cout << endl;
    cout << "中序遍历序列:" << endl;
    T.InOeder();
    cout << endl;
    cout << "后序遍历序列" << endl;
    T.PostOrder();
    cout << endl;
    cout << "叶子结点的个数: " << T.LeafNum() << endl;
    system("pause");
    return 0;
}