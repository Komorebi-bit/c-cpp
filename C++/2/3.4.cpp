#include  <iostream>
#include  <stdio.h>
using  namespace  std;

int  firMinIndex  =  -1,secMinIndex  =  -1;

void  findMin(int  *pArr,int  len)
{
    int i, j;
    int min =99999999;
    for ( i = 0; i < len;i++)
    {
        if(min>pArr[i])
        {
            min = pArr[i];
            firMinIndex = i;
        }
    }
    int cmin =99999999;
    for ( j = 0; j < len;j++)
    {
        if(j==firMinIndex||min==pArr[j])
            continue;
        if(cmin>pArr[j])
        {
            cmin = pArr[j];
            secMinIndex = j;
        }
    }
}
int  main()
{
        int  n;
        cin  >>  n;
        int  data[n];
        for(int  i=  0;i  <  n;i++)
                cin  >>  data[i];

        findMin(data,n);
        cout  <<  firMinIndex<<"  "<<secMinIndex<<endl;
        system("pause");
        return  0;
}