#include  <iostream>
#include  <stdio.h>
using  namespace  std;
void  sortArr(int  arr[],int  len,int(*compare)(int,int));
int  ascending(int  a,int  b);
int  descending(int  a,int  b);
int  main()
{
        int  n;
        cin  >>  n;
        int  data[n];
        for(int  i  =  0;  i  <  n;  i++)
                cin  >>  data[i];
        int  order;    //order=1是升序；order=0是降序
        cin  >>  order;
        int  (*pFun)(int,int);//声明一个函数指针
        if(order  ==  1)
                pFun  =  ascending;
        else
                pFun  =  descending;
        sortArr(data,n,pFun);
        for(int  i  =  0;  i  <  n;i++)
                cout<<data[i]<<"  ";
        cout<<endl;
        system("pause");
        return  0;
}
void  sortArr(int  arr[],int  len,int(*compare)(int,int)){
    int i = 0, j = 0;
    for (i = 0; i < len;i++)
    {
        for (j = 0; j < len-1;j++)
        {
             if (!compare(arr[j], arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int  ascending(int  a,int  b){
        return  a  <  b;
}
int  descending(int  a,int  b){
        return  a  >  b;
}