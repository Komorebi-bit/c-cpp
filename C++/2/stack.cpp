const int StackSize = 100;

template<typename T>
class Stack{
    public:
        Stack();
        ~Stack();
        void Push(T x);
        T Pop();
        T GetPop();
        int Empty();
        int Match(string s);

    private:
        T data[StackSize];
        int top;
};

template<typename T>
Stack<T>::Stack(){
    top = -1;
}

template<typename T>
Stack<T>::~Stack(){}

template<typename T>
void Stack<T>::Push(T x){
    if(top==StackSize-1)
        throw "上溢";
    top++;
    data[top] = x;
}

template<typename T>
T Stack<T>::Pop(){
    if(-1==top)
        throw "下溢";
    T x = data[top];
    top--;
    return x;
}

template<typename T>
T Stack<T>::GetPop(){
    if(-1==top)
        throw "空栈";
    return data[top];
}

template<typename T>
int Stack<T>::Empty(){
    if(-1==top)
        return 1;
    else
        return 0;
}

template<typename T>
int Stack<T>::Match(string s){
    for (int i = 0; s[i] != '\0';i++){
        if('('==s[i]){
            Push(s[i]);
        }
        if(')'==s[i]){
            if(top>-1){
                Pop();
            }else{
                return -1;
            }
        }
    }
    if(-1==top){
        return 0;
    }else{
        return 1;
    }
}