#include<iostream>
using namespace std;

int main(){

    //插入排序
    int n = 7;
    int data[n];
    // for (int i = 0; i < n;i++){
    //     cin >> data[i];
    // }
    // void insertsort(int[], int);
    // insertsort(data, n);
    // for (int i = 0; i < n;i++)
    //     cout << data[i] << " ";
    // cout << endl;

    //希尔排序
    // for (int i = 0; i < n;i++){
    //     cin >> data[i];
    // }
    // void shellsort(int data[], int len);
    // shellsort(data, n);
    // for (int i = 0; i < n;i++)
    //     cout << data[i] << " ";
    // cout << endl;

    //起泡排序
    // for (int i = 0; i < n;i++){
    //     cin >> data[i];
    // }
    // void bubblesort(int data[], int len);
    // bubblesort(data, n);
    // for (int i = 0; i < n;i++)
    //     cout << data[i] << " ";
    // cout << endl;

    //快速排序
    // for (int i = 0; i < n;i++){
    //     cin >> data[i];
    // }
    // void quicksort(int[], int, int);
    // quicksort(data, 0, n - 1);
    // for (int i = 0; i < n;i++)
    //     cout << data[i] << " ";
    // cout << endl;

    //简单选择排序
    // for (int i = 0; i < n;i++){
    //     cin >> data[i];
    // }
    // void selectsort(int[], int);
    // selectsort(data,n);
    // for (int i = 0; i < n;i++)
    //     cout << data[i] << " ";
    // cout << endl;

    //堆排序
    for (int i = 0; i < n;i++){
        cin >> data[i];
    }
    void (int[], int);
    (data,n);
    for (int i = 0; i < n;i++)
        cout << data[i] << " ";
    cout << endl;


    
    system("pause");
    return 0;
}

//插入排序
void insertsort(int data[],int len)
{
    int i, j, temp;
    for (i = 1; i < len;i++){
        temp = data[i];
        for (j = i-1; j >= 0 && temp<data[j];j--){
            data[j+1] = data[j];
        }
        data[j + 1] = temp;
    }
}

//希尔排序
void shellsort(int data[], int len)
{
    int d, i, j, temp;
    for (d = len / 2; d > 0;d/=2){
        for (i = d; i < len;i++){
            temp = data[i];
            for (j = i - 1; j >= 0 && temp < data[j];j--)
                data[j+1] = data[j];
            data[j + 1] = temp;
        }
    }
}

//起泡排序
void bubblesort(int data[],int len)
{
    int i, exchange, bound, temp;
    exchange = len - 1;
    while(exchange!=0){
        bound = exchange;
        exchange = 0;
        for (i = 0; i < bound;i++){
            if(data[i]>data[i+1]){
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                exchange = i;
            }
        }
    }
}

//快速排序
//partition函数放后面会显示找不到。
int partition(int data[],int first,int last)
{
    int i = first, j = last, temp;
    while(i<j){
        while(i<j && data[i]<=data[j])
            j--;
        if(i<j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
        }
        while(i<j && data[i]<=data[j])
            i++;
        if(i<j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            j--;
        }
    }
    return i;
}
void quicksort(int data[],int first, int last)
{
    if(first>=last)
        return;
    else{
        int pivot = partition(data, first, last);
        quicksort(data, first, pivot - 1);
        quicksort(data, pivot + 1, last);
    }
}

//简单选择排序
void selectsort(int data[],int len)
{
    int i, j, index, temp;
    for (i = 0; i < len - 1;i++){
        index = i;
        for (j = i + 1; j < len;j++){
            if(data[j]<data[index])
                index = j;
        }
        if(index!=i){
            temp = data[i];
            data[i] = data[index];
            data[index] = temp;
        }
    }
}

//堆排序

