template <typename T>
struct Node
{
    int data;
    struct Node<T> *next;
};

template <typename T>
class List
{
public:
    List();
    List(T a[], int n);
    ~List();
    int Length();
    T Get(int i);
    int Locate(T x);
    void Insert(int i, T x);
    T Delete(int i);
    int Empty();
    void PrintList();
    void Judge();
    void PrintListIncrease();
    void DeleteSame();
    void Combine(List<T> &l);
    Node<T>* get();

private:
    Node<T> *first;
};
template <typename T>
Node<T>* List<T>::get(){
    return first;
}
template <typename T>
List<T>::List()
{
    first = new Node<T>;
    first->next = nullptr;
}
template <typename T>
List<T>::List(T a[], int n)
{
    first = new Node<T>;
    Node<T> *r = first, *s = nullptr;
    for (int i = 0; i < n; i++)
    {
        s = new Node<T>;
        s->data = a[i];
        s->next = nullptr;
        r->next = s;
        r = s;
    }
}
template <typename T>
List<T>::~List()
{
    Node<T> *p;
    while (first != nullptr)
    {
        p = first;
        first = first->next;
        delete p;
    }
}
template <typename T>
int List<T>::Length()
{
    int length = 0;
    Node<T> *p = first->next;
    while (p != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}
template <typename T>
T List<T>::Get(int i)
{
    Node<T> *p = first->next;
    int count = 1;
    while (p != nullptr && count < i)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr)
        throw "该元素不存在";
    else
    {
        return p->data;
    }
}
template <typename T>
int List<T>::Locate(T x)
{
    Node<T> *p = first->next;
    int count = 1;
    while (p != nullptr)
    {
        if (x == p->data)
            return count;
        p = p->next;
        count++;
    }
    return 0;
}
template <typename T>
void List<T>::Insert(int i, T x)
{
    Node<T> *p = first;
    int count = 0;
    while (p != nullptr && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr)
        throw "插入位置错误";
    else
    {
        Node<T> *s = new Node<T>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}
template <typename T>
T List<T>::Delete(int i)
{
    Node<T> *p = first->next;
    int count = 1;
    T x;
    while (p != nullptr && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr)
        throw "删除位置错误";
    else
    {
        Node<T> *q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}
template <typename T>
int List<T>::Empty()
{
    if (first->nest == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
template <typename T>
void List<T>::PrintList()
{
    Node<T> *p = first->next;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
template <typename T>
void List<T>::PrintListIncrease()
{
    Node<T> *p = first->next;
    T a[Length()];
    int i = 0;
    while (p != nullptr)
    {
        a[i] = p->data;
        i++;
        p = p->next;
    }
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < i - j - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                T temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
    for (int j = 0; j < Length(); j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
}
template <typename T>
void List<T>::Judge()
{
    Node<T> *p = first->next, *q = p->next;
    while (p != nullptr && q != nullptr)
    {

        if (p->data > q->data)
        {
            cout << "单链表非递增有序" << endl;
            return;
        }
        p = p->next;
        q = p->next;
    }
    cout << "单链表递增有序" << endl;
}
template <typename T>
void List<T>::DeleteSame(){
    Node<T> *p = first->next;
    if(p==nullptr)
        return;
    while(p!=nullptr){
        Node<T> *q = p->next, *s = p;
        if(q==nullptr)
            return;
        while(q!=nullptr){
            if(p->data==q->data){
                s->next = q->next;
                delete q;
                q = s->next;
            }
            else{
                s = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}
template<typename T>
void List<T>::Combine(List<T> &l){
    Node<T> *pre = first, *qre = l.first;
    Node<T> *p = pre->next ,*q = qre->next;
    while(p!=nullptr && q!=nullptr){
        if((p->data)>=(q->data)){
            pre->next = q;
            qre->next = q->next;
            q->next = p;
            pre=pre->next;

        }else{
            pre=pre->next;

        }
        p = pre->next;
        q = qre->next;
        if(p==nullptr){
            pre->next = q;
            qre->next = nullptr;
        }

    }
}