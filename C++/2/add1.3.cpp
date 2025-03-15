#include<iostream>
using namespace std;
//大于1的非素数整数（即合数）都可以唯一分解成若干个素数的乘积;求这个合数可以分解成的素数.
int main()
{
    int n=0,j=0,s=1;
    int arr[20]={0};
    cin >> n;
    while(n!=1)
    {
        int i = 2;
        while(i)
        {

            if(n%i==0)
            {
                arr[j] = i;
                s *= arr[j];
                j++;
                n /= i;
                break;
            }
            else i++;
        }
    }
    for (int i = 0; i < j;i++)
        cout << arr[i]<<" ";
    system("pause");
    return 0;
}