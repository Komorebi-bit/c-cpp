#include<iostream>
using namespace std;

template<typename T>
struct BiNode
{
    T data;
    BiNode<T> *lchild, *rchild;
};

class BiSortTree
{
    public:
        BiSortTree(int a[], int n);
        ~BiSortTree() { Release(root); }
        BiNode<int> *InsertBST(int x) { return InsertBST(root, x); }
        int DeleteBST(int k) { return DeleteBST(root,k); }
        BiNode<int> *SearchBST(int k) { return SearchBST(root, k); }
        void InOrder() { InOrder(root); }

    private:
        BiNode<int> *InsertBST(BiNode<int> *bt, int x);
        BiNode<int> *SearchBST(BiNode<int> *bt, int k);
        int  DeleteBST(BiNode<int> *bt, int k);
        void Release(BiNode<int> *bt);
        void InOrder(BiNode<int> *bt);
        BiNode<int> *root;
};

BiSortTree::BiSortTree(int a[], int n)
{
    root = nullptr;
    for (int i; i < n;i++){
        root = InsertBST(root,a[i]);
    }
}

void BiSortTree::Release(BiNode<int> *bt)
{
    if(bt==nullptr)
        return;
    Release(bt->lchild);
    Release(bt->rchild);
    delete bt;
}

void BiSortTree::InOrder(BiNode<int> *bt)
{
    if(bt==nullptr)
        return;
    InOrder(bt->lchild);
    cout << bt->data << " ";
    InOrder(bt->rchild);
}

BiNode<int> *BiSortTree::InsertBST(BiNode<int> *bt, int x)
{
    if(bt==nullptr){
        BiNode<int> *s = new BiNode<int>;
        s->data = x;
        s->lchild = nullptr;
        s->rchild = nullptr;
        bt = s;
        return bt;
    }
    if(bt->data>x)
        bt->lchild = InsertBST(bt->lchild, x);
    if(bt->data<x)
        bt->rchild = InsertBST(bt->rchild, x);
    return bt;
}

BiNode<int> *BiSortTree::SearchBST(BiNode<int> *bt, int k)
{
    if(bt==nullptr)
        return nullptr;
    if(k==bt->data)
        return bt;
    if(k<bt->data)
        return SearchBST(bt->lchild, k);
    else
        return SearchBST(bt->rchild, k);
}

int BiSortTree::DeleteBST(BiNode<int>* bt,int k)
{
    BiNode<int> *p = bt, *f = bt;
    while(p!=nullptr)
    {
        if(p->data == k)
            break;
        if(p->data > k){
            f = p;
            p = p->lchild;
        }
        if(p->data < k){
            f = p;
            p = p->rchild;
        }
    }
    if(p==nullptr)
        return 0;
    if(p==bt){
        return -1;
    }
    if(p->lchild == nullptr && p->rchild == nullptr){
        if(p==f->lchild){
            f->lchild = nullptr;
        }
        if(p==f->rchild){
            f->rchild = nullptr;
        }
        delete p;
        return 1;
    }
    if(p->lchild == nullptr){
        if(p==f->lchild){
            f->lchild = p->rchild;
        }
        if(p==f->rchild){
            f->rchild = p->rchild;
        }
        delete p;
        return 1;
    }
    if(p->rchild == nullptr){
        if(p==f->lchild){
            f->lchild = p->lchild;
        }
        if(p==f->rchild){
            f->rchild = p->lchild;
        }
        delete p;
        return 1;
    }
    BiNode<int> *s = p->rchild,*par = p;
    while(s->lchild!=nullptr){
        par = s;
        s = s->lchild;
    }
    p->data = s->data;
    if(par == p){
        p->rchild = s->rchild;
    }else{
        par->lchild = s->rchild;
    }
    delete s;
    return 1;

}

int main()
{
    int n;
    cout << "输入构造二叉排序树的元素个数:" << endl;
    cin >> n;
    int a[n];
    cout << "输入个元素值:" << endl;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    BiSortTree bst(a, n);
    cout << "遍历二叉排序树:" << endl;
    bst.InOrder();
    cout << endl;

    int x;
    cout << "输入待插入的元素:" << endl;
    cin >> x;
    bst.InsertBST(x);
    cout << "遍历二叉排序树:" << endl;
    bst.InOrder();
    cout << endl;

    cout << "输入待查找的元素:" << endl;
    cin >> x;
    if((bst.SearchBST(x))->data == x){
        cout <<x<<"在二叉排序树中"<< endl;
    }else{
        cout <<x<<"未找到该节点"<< endl;
    }

    cout << "输入要删除的元素" << endl;
    cin >> x;
    if(1 == bst.DeleteBST(x)){
        cout << "删除成功" << endl;
    }
    if(-1 == bst.DeleteBST(x)){
        cout << "无法删除头节点!!!" << endl;
    }
    else{
        cout << "未找到该节点" << endl;
    }
    cout << "遍历二叉排序树:" << endl;
    bst.InOrder();
    cout << endl;

    system("pause");
    return 0;
}