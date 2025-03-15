#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int max=a[0], cmax=a[n-1];
    for (int i = 1; i < n;i++){
        if(a[i]>max){
            cmax = max;
            max = a[i];
        }
        else{
            if(a[i]>cmax){
                cmax = a[i];
            }
        }
    }
    cout << "最大值: " << max << "  次最大值: " << cmax << endl;
    system("pause");
    return 0;
}