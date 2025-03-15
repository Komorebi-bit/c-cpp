#include <iostream>
#include <vector>

// #define DEBUG

using namespace std;

/* 相似字符串组 */
/*
如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。
如果这两个字符串本身是相等的，那它们也是相似的。
例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，
但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。
总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。
注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。
形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。
请问 strs 中有多少个相似字符串组？
示例 1：
输入：strs = ["tars","rats","arts","star"]
输出：2

示例 2：
输入：strs = ["omv","ovm"]
输出：1

提示：
1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] 只包含小写字母。
strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。
*/

int numSimilarGroups(vector<string> &strs);
int isSimilar(string& s1, string& s2);

int find(int a[], int i);
void merge(int a[], int i, int j);

int main()
{
    vector<string> strs = {"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"};

    int res = numSimilarGroups(strs);
    cout << res <<endl;

    system("pause");
    return 0;
}
int numSimilarGroups(vector<string>& strs)
{
    int n = strs.size();
    int a[n];
    for(int i=0;i<n;i++)
        a[i] = -1;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n;j++)
        {
            if(isSimilar(strs[i], strs[j]))
            {
                //并查集 合并操作
                merge(a, i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
#ifdef DEBUG
        cout << a[i] << " ";
#endif
        if(a[i] == -1)
            count++;
    }
#ifdef DEBUG
    cout << endl;
#endif
    return count;
}

int isSimilar(string& s1,string& s2) //改为引用，耗时大为减少
{
    // char a, b;
    int flag = 0;
    for (int i = 0; i < (int)s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            flag++;
            if (flag > 2) {
                return false;
            }
        }
        // if(s1[i] != s2[i])
        // {
        //     if(flag == 0)
        //     {
        //         a = s1[i];
        //         b = s2[i];
        //         flag++;
        //     }
        //     else if(flag == 1)
        //     {
        //         flag++;
        //         if(a != s2[i] || b != s1[i])
        //             return 0;
        //     }
        //     else
        //         return 0;
        // }
    }
    return 1;
}

// 并查集 查操作
int find(int a[],int i)
{
    while(a[i] != -1)
        i = a[i];
    return i;
}

// 并查集 合并操作
void merge(int a[], int i, int j)
{
    int r1 = find(a, i);
    int r2 = find(a, j);
    if(r1 != r2)
    {
        a[r2] = r1;
        if(r2 != j)
            a[j] = r1;
        if(r1 != i)
            a[i] = r1;
    }
}