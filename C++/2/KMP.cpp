#include<iostream>
#include<cstring>
using namespace std;

int main(){
    cout << "输入主串,然后换行输入模式串" << endl;
    string S,T;
    cin >> S >> T;
    int KMP(string&, string&);
    int val = KMP(S, T);
    if(val>=0)
        cout << "匹配成功,模式串在主串的位置(从0开始)为:"<< val << endl;
    if(val<0)
        cout << "匹配失败" << endl;
    system("pause");
    return 0;
}

int KMP(string &S,string &T){
    int len1 = S.length();
    int len2 = T.length();
    int next[len2] = {-1, 0};
    for (int j = 2; j < len2;j++)
    {
        for (int n = 1; n < j;n++)
        {
            if(T.substr(0, n)==T.substr(j - n,n)){
                 next[j] = n;
            }

        }
    }
    // for (int i = 0; i < len2;i++){
    //     cout << next[i] << " ";
    // }
    // cout << endl;

    int i = 0, j = 0, start = 0;

    while(i < len1 && j < len2){
        if(S[i]!=T[j]){
            j = next[j];
            start = i;
        }
        if(S[i] == T[j] ){
            // cout << i << "    " << j << endl;
            i++;
            j++;

        }
        if(-1 ==j ){
            i++;
            j++;
            start = i;
        }
    }
    // cout << j << endl;
    if(j == len2)
        return start;
    else
        return -1;
}