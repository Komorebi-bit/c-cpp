#include<iostream>
#include<string>
using namespace std;
#include"stack.cpp"

int main(){
    Stack<char> stack;
    stack.Push('#');
    string s;
    cout << "请输入正确表达式, 并放入#之间!"<<endl;
    cin >> s;
    for (int i = 1; s[i]!='\0';i++){
        while(s[i] >= '0' && s[i] <= '9'){
            cout << s[i];
            i++;
            continue;
        }
        cout << " ";
        if(s[i]=='#'){
            while(stack.GetPop()!='#'){
                cout << stack.Pop()<<" ";
            }
            break;
        }
        if(s[i]=='('){
            stack.Push(s[i]);
            continue;
        }
        if(s[i]==')'){
            while(stack.GetPop()!='('){
                cout << stack.Pop()<<" ";
            }
            stack.Pop();
            continue;
        }
        int compare(char c1, char c2);
        int a = compare(stack.GetPop(), s[i]);
        if(a==-100)
            throw "输入有错误";
        switch(a){
            case -1:
                stack.Push(s[i]);
                break;
            case 0:
                if(s[i]=='/'||s[i]=='*'||s[i]=='-'||s[i]=='+'){
                    cout<<stack.Pop()<<" ";
                    stack.Push(s[i]);
                    break;
                }
                break;
            case 1:
                cout<<stack.Pop()<<" ";
                stack.Push(s[i]);
                break;
        }

    }
    cout << endl;
    system("pause");
    return 0;
}

int compare(char c1,char c2){
    if(c1=='#'&&(c2=='('||c2=='/'||c2=='*'||c2=='-'||c2=='+')){
        return -1;
    }else if(c2=='#'&&(c1=='('||c1=='/'||c1=='*'||c1=='-'||c1=='+')){
        return 1;
    }else if(c1=='('&&(c2=='/'||c2=='*'||c2=='-'||c2=='+')){
        return -1;
    }else if(c2=='('&&(c1=='/'||c1=='*'||c1=='-'||c1=='+')){
        return 1;
    }else if((c1=='/'||c1=='*')&&(c2=='-'||c2=='+')){
        return 1;
    }else if((c2=='/'||c2=='*')&&(c1=='-'||c1=='+')){
        return -1;
    }else if(c1==c2||(c1=='/'&&c2=='*')||(c1=='*'&&c2=='/')||(c1=='-'&&c2=='+')||(c1=='+'&&c2=='-')){
        return 0;
    }else{
        return -100 ;
    }
}