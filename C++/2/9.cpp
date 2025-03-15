#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a[100];
    ifstream infile("D:/new/1.txt",ios::in);
    if(!infile)
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    for (int i = 0; i < 100;i++)
    {
        if(!infile)
            break;
        infile >> a[i];
        cout << a[i] << " ";
    }
    infile.close();
    system("pause");
    return 0;
}