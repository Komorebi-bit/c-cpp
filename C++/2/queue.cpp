const int QueueSize = 100;

template<typename T>
class Queue{
    public:
        Queue();
        ~Queue();
        void InQueue(T x);
        T OutQueue();
        T GetHead();
        int Empty();
    private:
        T data[QueueSize];
        int front, rear;
};

template<typename T>
Queue<T>::Queue(){
    front = QueueSize - 1;
    rear = QueueSize - 1;
}

template<typename T>
Queue<T>::~Queue(){}

template <typename T>
void Queue<T>::InQueue(T x){
    if((rear+1)%QueueSize==front)
        throw "上溢";
    rear = (rear + 1) % QueueSize;
    data[rear] = x;
}

template<typename T>
T Queue<T>::OutQueue(){
    if(rear==front)
        throw "下溢";
    front = (front + 1) % QueueSize;
    return data[front];
}

template<typename T>
T Queue<T>::GetHead(){
    if(rear==front)
        throw "下溢";
    return data[(front + 1) % QueueSize];
}

template<typename T>
int Queue<T>::Empty(){
    if(rear==front){
        return 1;
    }else{
        return 0;
    }
}
