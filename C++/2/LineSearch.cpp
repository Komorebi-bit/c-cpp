#include<iostream>
using namespace std;

const int MaxSize = 100;
class LineSearch
{
    public:
        LineSearch(int a[],int n);
        ~LineSearch(){}
        int SeqSearch(int k);
        int BinSearch(int k);
        int BinSearch(int low, int high, int k);

    private:
        int data[MaxSize];
        int length;
};
LineSearch::LineSearch(int a[],int n)
{
    for (int i = 0; i < n;i++)
    {
        data[i + 1] = a[i];
    }
    length = n;
}

int LineSearch::SeqSearch(int k)
{
    int i = length;
    data[0] = k;
    while(data[i]!=k)
        i--;
    return i;
}

int LineSearch::BinSearch(int k)
{
    int mid, low = 1, high = length;
    while(low<=high)
    {
        mid = (low + high) / 2;
        if(k<data[mid])
            high = mid-1;
        if(k>data[mid])
            low = mid + 1;
        if(k==data[mid])
            return mid;
    }
    return 0;
}

int LineSearch::BinSearch(int low, int high, int k)
{
    if(low>high)
        return 0;
    int mid = (low + high) / 2;
    if(k<data[mid])
        return BinSearch(low, mid - 1, k);
    if(k>data[mid])
        return BinSearch(mid + 1, high, k);
    return mid;
}

int main()
{
    cout << "输入顺序表的长度:" << endl;
    int n;
    cin >> n;
    cout << "输入顺序表各个元素:" << endl;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    cout << "输入带查找的元素:" << endl;
    int k;
    cin >> k;
    LineSearch ls1(a, n);
    int m = ls1.SeqSearch(k);
    if(m==0)
        cout << "查找的元素不存在!!!" << endl;
    else
        cout << "找到了，在第"<<m<<"个位置" << endl;
    // int n,k,m;
    cout << "输入有序表的长度:" << endl;
    cin >> n;
    int b[n];
    cout << "输入有序表各个元素(递增的顺序):" << endl;
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    cout << "输入带查找的元素:" << endl;
    cin >> k;
    LineSearch ls2(b, n);
    m = ls2.BinSearch(k);
    if(m==0)
        cout << "查找的元素不存在!!!" << endl;
    else
        cout << "找到了，在第"<<m<<"个位置" << endl;
    system("pause");
    return 0;
}
