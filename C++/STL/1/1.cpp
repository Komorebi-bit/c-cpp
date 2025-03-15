#include <iostream>
#include <string>
#include <map>

// #define DEBUG

using namespace std;

//统计字符串中，出现的次数最多的单词，并输出
/*
The quick brown fox jumps over the lazy dog.
The dog was not amused by the fox's antics.
The fox, in turn, was quite pleased with itself.
*/

int main()
{
    int n;
    cin >> n;
    string str[n];
    //getchar();
    for (int i = 0; i < n; i++)
    {
        //getchar();
        getline(cin, str[i]);
    }

    map<string, int> mp;
    map<string, int>::iterator it;

    for (int j = 0; j < 3; j++)
    {
        string s = "";
        for (int i = 0; i < (int)str[j].size(); i++)
        {
            if(str[j][i]>='A'&&str[j][i]<='Z')
                s += str[j][i];
            else if(str[j][i]>='a'&&str[j][i]<='z')
                s += str[j][i];
            else if (str[j][i] == '\'')
            {
                s += '\'';
            }
            else
            {
                if(s!=""){
                    it = mp.find(s);
                    if(it == mp.end())
                        mp.insert({s, 1});
                    else
                        (it->second)++;
                }
                s = "";
            }
        }
    }
    int max = 0;
    string res = "";
    for (auto &i : mp)
    {
        if(i.second>max)
        {
             res = i.first;
             max = i.second;
        }
    }


#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    for (auto &i : mp)
    {
        cout << i.first << ": " << i.second << endl;
    }

#endif

    cout << res << endl;

    system("pause");
    return 0;
}
