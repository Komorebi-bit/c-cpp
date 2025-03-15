#include <iostream>
#include <map>

// #define DEBUG

using namespace std;

//基本计算器
/*
9
1+1+1+1
5+4*2/3
6*5+3*2
5+2/0+9
5+(1+1)+9
2*(5+10)/3
5+(2+3)*2
5*(3-2)-5
5*(3-2)-5+5+(2+3)*2
*/
/* 4 7 36 -1 16 10 15 0 15 */

namespace my
{
    int exp = 0; //1：运算出现异常情况，0：无异常
}

void calculate(string s);
int _calculate(char c, int a, int b);

map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; //定义运算符优先级

int main()
{
    int n;
    cin >> n;
    string strs[n];
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    for (int i = 0; i < n; i++)
    {
        calculate(strs[i]);
    }
// #ifdef DEBUG
//     calculate("5+(1+1)+9");
// #endif
    system("pause");
    return 0;
}

void calculate(string s)
{
    int nums[10] = {0};  // 数据栈 栈顶指针j 指向栈顶元素（非栈顶元素后一位）
    char sm[10] = {0};   // 运算符栈 栈顶指针k 指向栈顶元素（非栈顶元素后一位）
    int rank[10] = {0};  // 运算符栈里的运算符对应的优先级
    int j = -1, k = 0;
    int temp = 0, flag = 0;  // flag: 标记temp是否存放了数据，默认否
    char ch = 0;
    for (int i = 0; i < (int)s.size() ; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            temp = temp * 10 + s[i] - '0';
            flag = 1;
        }else
        {
            if(flag)
            {
                nums[++j] = temp;
                temp = 0;
                flag = 0;
            }
            ch = s[i];
            if(ch == '(')
            {
                sm[++k] = s[i]; //直接入栈
                rank[k] = 0;
            }
            else if(ch == ')')
            {
                while(sm[k]!='(') // 运算符出栈，直到遇到'('
                {
                    int rr = _calculate(sm[k],nums[j-1],nums[j]);
                    if(my::exp)
                    {
                        cout << -1 << endl;
                        return;
                    }
                    nums[--j] = rr; // 运算结果入栈
                    k--;
                }
                k--; // '('出栈
            }else
            {
                int r = (mp.find(ch))->second;  //当前 运算符 的 优先级
                if(r<=rank[k])
                {   //当前运算符的优先级小于栈顶运算符的优先级
                    int rr = _calculate(sm[k],nums[j-1],nums[j]);  //运算符出栈，计算表达式
                    if(my::exp)
                    {
                        cout << -1 << endl;
                        my::exp = 0;
                        return;
                    }
                    nums[--j] = rr;   //两个运算数出栈，运算结果入栈；
                    sm[k] = s[i];   //当前运算符入栈
                    rank[k] = r;
                }else
                {
                    sm[++k] = s[i]; //不小于，直接入栈
                    rank[k] = r;
                }
            }
        }
    }
    if(flag)
        nums[++j] = temp;
    while(k) //直到运算符栈空为止
    {
        int rr = _calculate(sm[k],nums[j-1],nums[j]);
        if(my::exp)
        {
            cout << -1 << endl;
            my::exp = 0;
            return;
        }
        nums[--j] = rr;
        k--;
    }

    cout << nums[0] << endl;
}

int _calculate(char c, int a, int b)
{
    int res = 0;
    switch (c)
    {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if(!b)
            { //处理除数为0的情况
                my::exp = 1;
                break;;
            }
            res = a / b;
            break;
        default:
            my::exp = 1;
            break;
    }
    return res;
}
