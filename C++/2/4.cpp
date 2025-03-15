#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a[10];
    ofstream outfile("D:/new/1.txt", ios::app);
    if(!outfile)
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    cout << "enter 10 integer numbers：" << endl;
    for (int i = 0; i < 10;i++)
    {
        cin >> a[i];
        outfile << a[i] << " ";
    }
    outfile.close();
    system("pause");
    return 0;
}