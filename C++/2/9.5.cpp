#include<iostream>
using namespace std;
int ans;
int main()
{
    int n;
    cin >> n;
    void f(int n, int step);
    f(n, 0);
    cout << ans << endl;
    system("pause");
    return 0;
}
//递归函数，n：阶梯书  step:步数，用于判断偶数的
void f(int n,int step)
{
	//走法不正确
	if(n<0){
		return;
	}
	//走完了 ，走法正确
	if(n==0&&step%2==0)
    {
		ans++;
	}
	f(n-1,step+1);//左脚//一步
	f(n-2,step+1);//右脚//二步
}
