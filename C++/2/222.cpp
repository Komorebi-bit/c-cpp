// #include<iostream>
// using namespace std;

// int main()
// {

//     int n,i;
//     cin >> n;
//     int a[100];
//     for (i = 0; i < n;i++)
//     {
//         cin >> a[i];
//     }

//     void bubbleSort(int arr[], int n);
//     bubbleSort(a,n);

//     for (i = 0; i < n; i++)
//     {
// 		cout<<a[i]<<' ';
// 	}
//     cout << endl;
//     system("pause");
//     return 0;
// }

// void bubbleSort(int arr[], int n)
// {
// 	for(int i = 0;i < n;i++){
// 		for(int j = 0;j < n-i-1;j++){
//             if(arr[j] > arr[j+1]){
//                 int t = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = t;
//             }
//         }
//     }
// }

#include<iostream>
using namespace std;

int main()
{

    // int i,shi,ge,bai,qian;
    // for(i=1001;i<10000;i++)
    //     {
    //         ge=i%10;
    //         shi=(i%100-i%10)/10;
    //         bai=(i%1000-i%100)/100;
    //         qian=(i-i%1000)/1000;
    //         if(ge==qian&&shi==bai)
    //         printf("%d\n",i);
    //     }

    int i,key,sum;
	for(i=1000;i<=9999;i++)
	{
		sum=0;
		key=i;
		while(key!=0)
		{
			sum=sum*10+key%10;
			key=key/10;
		}
		if(sum==i)
		{
            cout << i << endl;
        }
	}
    system("pause");
    return 0;
}
