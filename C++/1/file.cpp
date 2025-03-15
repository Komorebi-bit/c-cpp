#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in;
    in.open("1/1.txt");
    if (in.is_open())
    {
        string line;
        while (getline(in, line))
            cout << line << '\n';
    }
    else
        cout << "Failed to open the file." << '\n';
    in.close();

    ofstream out;
    out.open("1/1.txt", ios::out | ios::app);
    if(out.is_open())
    {
        out << "ostream..." << '\n';
    }else
        cout << "Failed to open the file." << '\n';
    out.close();

    system("pause");
    return 0;
}
