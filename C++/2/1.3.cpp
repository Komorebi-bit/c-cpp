#include<iostream>
using namespace std;

int main()
{
    int arr[3];
    for (int i = 0; i < 3;i++)
    {
        cin >> arr[i];
    }
    if (arr[0] + arr[1] <= arr[2] || arr[0] + arr[2] <= arr[1] || arr[1] + arr[2] <= arr[0])
        cout<<"It is not a triangle"<<endl;
    else if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]||arr[0]*arr[0]+arr[2]*arr[2]==arr[1]*arr[1]||arr[2]*arr[2]+arr[1]*arr[1]==arr[0]*arr[0])
        {
            int maxv = arr[0];
            for (int i = 1; i < 3;i++)
            {
                if (maxv < arr[i])
                    maxv = arr[i];
            }
            int minv = arr[0];
            for (int i = 1; i < 3;i++)
            {
                if (minv > arr[i])
                    minv = arr[i];
            }
            for (int i = 2; i<=minv;i++)
            {
                if( minv % i == 0 && maxv % i == 0 )
                {
                    minv /= i;
                    maxv /= i;
                }
            }
            cout << minv << "/" << maxv << endl;
        }
    else
        cout<<"It is not a right triangle"<<endl;
    system("pause");
    return 0;
}