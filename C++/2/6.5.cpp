#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

typedef struct student
{
    string name;
    int score;
} student;
int main()
{
    int n;
    cin >> n;
    student *p = new student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].score;
    }
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n-i-1;j++)
            if(p[j].score<p[j+1].score)
            {
                student temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
    for (int i = 0; i < n;i++)
        cout << setw(15) << p[i].name << setw(5) << p[i].score << endl;
    system("pause");
    return 0;
}