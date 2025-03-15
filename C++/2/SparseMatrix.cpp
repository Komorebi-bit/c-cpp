#include<iostream>
using namespace std;

const int MaxTerm = 100;

template<typename T>
struct element{
    int row, col;
    T item;
};

template<typename T>
class SparseMatrix{
    private:
        struct element<T> *data;
        int mu, nu, tu;
    public:
        SparseMatrix();
        SparseMatrix(struct element<T> data[], int mu, int nu, int tu);
        void transposedMatrix(SparseMatrix<T> &A,SparseMatrix<T> &B);
        void output();
};

template<typename T>
SparseMatrix<T>::SparseMatrix(){}

template<typename T>
SparseMatrix<T>::SparseMatrix(struct element<T> data[], int mu, int nu, int tu){
    this->data = data;
    this->mu = mu;
    this->nu = nu;
    this->tu = tu;
}

template<typename T>
void SparseMatrix<T>::transposedMatrix (SparseMatrix<T> &A,SparseMatrix<T> &B){
    int i = 0, j = 0, k = 0, num[A.nu] = {0}, cpot[A.tu];
    B.mu = A.nu, B.nu = A.mu, B.tu = A.tu;
    for (i = 0; i < B.tu;i++){
        j = A.data[i].col;
        num[j]++;
    }
    cpot[1] = 0;
    for (i = 2; i <= A.nu; i++){
        cpot[i] = cpot[i - 1] + num[i - 1];
    }
    for (i = 0; i < A.tu; i++){
        j = A.data[i].col;
        k = cpot[j];
        B.data[k].item = A.data[i].item;
        B.data[k].col = A.data[i].row;
        B.data[k].row = A.data[i].col;
        cpot[j]++;
    }
}

template<typename T>
void SparseMatrix<T>::output(){
    for (int i = 0; i < tu;i++){
        cout << data[i].row <<'\t'<< data[i].col <<'\t'<< data[i].item << endl;
    }
    cout << endl;
    cout << "矩阵的行数"<< mu <<'\t'<< "列数" << nu <<'\t'<< "非〇元素的个数"<< tu<<endl;
}



int main(){
    struct element<int> data[MaxTerm];
    struct element<int> data1[MaxTerm];
    int mu,nu,tu;
    cout << "输入非零元素的个数: " << endl;
    cin >> tu;
    cout << "依次输入非〇元素所在的行号，列号及值:" << endl;
    for (int i = 0; i < tu;i++){
        cin >> data[i].row >> data[i].col >> data[i].item;
    }
    cout << "输入矩阵的行数列数:" << endl;
    cin >> mu >>nu;
    SparseMatrix<int> A(data,mu,nu,tu);
    SparseMatrix<int> B(data1,mu,nu,tu);
    A.transposedMatrix(A, B);

    cout << "三元顺序表A: " << endl;
    A.output();
    cout << endl
         << endl;
    cout << "三元顺序表B: " << endl;
    B.output();

    system("pause");
    return 0;
}