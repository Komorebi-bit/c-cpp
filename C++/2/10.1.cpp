#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int f(int, int);
	cout<<f(n,0);
	system("pause");
	return 0;
}
int f(int n,int t)
{
	if(n == 1)
		return t;
	else if(n%2 == 0)
	{
		t++;
		f(n/2,t);
	}
	else if(n%2 == 1)
	{
		t++;
		f(n*3+1,t);
	}
}

