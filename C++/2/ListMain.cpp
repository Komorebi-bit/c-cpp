#include<iostream>
using namespace std;
#include"List.cpp"

int main(){
    cout << "输入单链表的长度:"<<endl;
    int n = 0;
    cin >> n;
    cout << "输入单链表中的各个元素(整数)"<<endl;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    List<int> l(a, n);
    l.Judge();
    cout << "按递增次序输出单链表" << endl;
    l.PrintListIncrease();
    cout << "输入插入的位置, 及值(整数)" << endl;
    int i = 0, x = 0;
    cin >> i >> x;
    try{
        l.Insert(i, x);
    }catch(char* str){
        cout << str << endl;
    }
    cout << "输出插入后的链表" << endl;
    l.PrintList();
    cout << "去重并输出链表" << endl;
    l.DeleteSame();
    l.PrintList();
    cout << "输入待查找的位置: " << endl;
    cin >> i;
    try{
    cout << l.Get(i) << endl;
    }catch(char* str){
        cout << str << endl;
    }
    int y,z;
    cout << "请输入第一个非递减单链表的大小" << endl;
    cin >> y;
    cout << "请输入第一个单链表中的各个元素(整数)" << endl;
    int b[y];
    for (int i = 0; i < y;i++){
        cin >> b[i];
    }
    List<int> l1(b, y);
    cout << "请输入第二个非递减单链表的大小" << endl;
    cin >> z;
    cout << "请输入第二个单链表中的各个元素(整数)" << endl;
    int c[z];
    for (int i = 0; i < z;i++){
        cin >> c[i];
    }
    List<int> l2(c, z);
    //l1.PrintList();
    //l2.PrintList();
    cout << "合并成一个非递减有序单链表,并输出: " << endl;
    l1.Combine(l2);
    l1.PrintList();
    system("pause");
    return 0;
}