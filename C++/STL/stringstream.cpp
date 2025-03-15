#include <iostream>
// #include <string>
#include <sstream>

using namespace std;

int main()
{
    string s("stringstream");
    stringstream ss1;
    ss1 << s;
    cout << ss1.str() << '\n'; // 调用str()函数，输出字符串

    stringstream ss2("stringstream");
    cout << ss2.str() << '\n';
    // cout << ss2.eof() << '\n';

    ss1 << "abc";
    cout << ss1.str() << '\n'; // stringstreamabc 直接拼接

    ss2 << "abc";
    cout << ss2.str() << '\n'; // abcingstream 首先把原本的字符串覆盖掉，之后再进行拼接。

    ostringstream ss3("1 2 3 4 ", ios_base::ate);
    ss3 << "5 6 7 ";
    cout << ss3.str() << '\n'; // 1 2 3 4 5 6 7

    ss2.str("stringstream"); // 修改
    cout << ss2.str() << '\n';
    ss2.str(""); // 清空
    cout << ss2.str() << '\n';

    // 默认是以空格来分割字符串的，利用stringstream去除字符串空格非常方便
    stringstream ss4("hello string and stringstream");
    string str;
    while (ss4 >> str) // 注意：stringstream是一个单词一个单词流入string的
        cout << str << '\n';
    cout << '#' <<ss4.eof() << ss2.fail() << ss2.good() << ss2.bad() << '\n'; // 1 0 1 0

    // 指定字符分割字符串
    stringstream ss5;
    ss5 << "abc,123,<!>";
    while (getline(ss5, str, ','))
        cout << str << '\n';

    stringstream ss6;
    int num = 246;
    ss6 << num; // int->strng
    cout << ss6.str() << '\n';

    int n;
    ss6 >> n; // string->int
    cout << n << '\n';

    // To clear a stringstream in C++,
    // you need to reset its content using the str method with an empty string.
    // This is necessary because the clear() method only resets the stream's state flags
    // (like error flags), not its content
    // 要清除 C++ 中的字符串流，需要使用 str 方法用空字符串重置其内容。
    // 这是必要的，因为 clear() 方法只能重置字符串流的状态标志（如错误标志），而不能重置其内容。
    ss6.str("");
    ss6.clear();
    ss6 << true;
    cout << ss6.str() << '\n';
    system("pause");
    return 0;
}
