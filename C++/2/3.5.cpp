#include  <iostream>
#include  <stdio.h>
using  namespace  std;
int**  create(int  row,int  col)
{
    int **q = new int *[row+1];
    for (int i = 0; i < row + 1;i++)
    {
        q[i] = new int[col + 1];
    }
    for (int i = 1; i <= row;i++)
        for (int j = 1; j <= col;j++)
            cin >> q[i][j];
    /*for (int i = 1; i <= row;i++)
    {
        for (int j = 1; j <= col;j++)
            cout<< q[i][j]<<" ";
        cout << endl;
    }*/
    return q;
}
int**  solve(int**  ptrA,int  rowA,int  colA,int**  ptrB,int  rowB,int  colB,int  row,int  col)
{
    int i = 1;
    int roww = row;
    while(roww<rowB+row&&roww<=rowA)
    {
        int coll = col;
        int j = 1;
        while(coll<colB+col&&coll<=colA)
        {
            ptrA[roww][coll] = ptrB[i][j];
            coll++;
            j++;
        }
        roww++;
        i++;
    }
    return ptrA;
}
void  show(int**  p,int  row,int  col)
{
        for(int  i  =  1;i  <=  row;i++){
                for(int  j  =  1;j<=  col;j++)
                        cout  <<  p[i][j]<<"  ";
                cout<<endl;
        }
}
int  main()
{
        int  rowA,colA;
        cin  >>  rowA  >>  colA;
        int**  A  =  create(rowA,colA);

        int  rowB,colB;
        cin  >>  rowB  >>  colB;
        int**  B  =  create(rowB,colB);

        int  row,col;
        cin  >>  row  >>  col;
        A  =  solve(A,rowA,colA,B,rowB,colB,row,col);
        show(A,rowA,colA);
        system("pause");
        return  0;
}
