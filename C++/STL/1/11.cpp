#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// 路径解析 ccf-csp

int main()
{
    int n;
    string path;
    cin >> n >> path;
    string str[n];
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
        if (str[i][0] != '/') // 不是绝对路径的，加上当前路径，拼接成绝对路径
            str[i] = path + '/' + str[i];
    }
    vector<string> v;
    stringstream ss;
    string s;
    for (int i = 0; i < n; i++)
    {
        ss << str[i];
        while (getline(ss, s, '/'))
        {
            if (s == "." || s == "")
                continue;
            else if (s == "..")
                if (!v.empty())
                    v.pop_back();
                else
                    continue;
            else
                v.push_back(s);
        }
        // cout << '#' <<ss.eof() << '\n';
        if (v.empty())
            cout << '/';
        else
            for (auto j : v)
                cout << '/' << j;
        cout << '\n';
        v.clear();
        ss.str(""); // 用完即使清空，不然会出现意想不到的结果！
        ss.clear(); // 一起使用
    }

    system("pause");
    return 0;
}

/*
7
/d2/d3
/d2/d4/f1
../d4/f1
/d1/./f1
/d1///f1
/d1/
///
/d1/../../d2

/d2/d4/f1
/d2/d4/f1
/d1/f1
/d1/f1
/d1
/
/d2
*/
