#include<iostream>
#include<fstream>
#include <Windows.h>
#include<string>
using namespace std;
string UTF8ToGB(const char* str)
{
     string result;
     WCHAR *strSrc;
     LPSTR szRes;

     //获得临时变量的大小
     int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
     strSrc = new WCHAR[i+1];
     MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

     //获得临时变量的大小
     i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
     szRes = new CHAR[i+1];
     WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

     result = szRes;
     delete []strSrc;
     delete []szRes;

     return result;
}
int main()
{
    char txt[10000];
    string msg;
    ifstream infile;
    infile.open("D:/new/2.txt");

    if(!infile.is_open())
    {
        cout<<""<<endl;
        exit(0);
    }

    while(!infile.eof())
    {
        infile.getline(txt,10000);
        msg=UTF8ToGB(txt);
        cout<<msg<<endl;

    }

    infile.close();
    system("pause");
    return 0;
}