#include<iostream>
#include<string>
using namespace std;
#include "stack.cpp"

int main(){
    Stack<char> stack;
    string s;
    cout << "请输入一个算数表达式: " << endl;
    cin >> s;
    int a = stack.Match(s);
    switch(a){
        case 0:
            cout << "匹配正确"<<endl;
            break;
        case -1:
            cout << "多右括号" << endl;
            break;
        case 1:
            cout << "多左括号" << endl;
            break;
    }
    system("pause");
    return 0;
}