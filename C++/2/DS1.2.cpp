#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0,j=len-1; i < (len+1)/2; i++,j--){
        if(s[i]!=s[j]){
            cout << "不是回文" << endl;
            system("pause");
            return 0;
        }
    }
    cout << "是回文" << endl;
    system("pause");
    return 0;
}