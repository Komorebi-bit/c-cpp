#include <iostream>
#include <stack> //包含头文件<deque>
#include <vector>
#include <list>

using namespace std;

int main()
{
   stack<int> s;

   // 容器的初始化

   //stack是基于deque实现的，相当于deque双端队列，封闭了一端
   //1、创建一个空的栈s1
   stack<int> s1;
   stack<int,list<int>> s1;

   //2、用vector容器初始化stack
   vector<int> v1={1,2,3,4};
   stack<int,vector<int>> s2(v1);   //1,2,3,4依次入栈

   //3、用deque容器初始化stack
   //用deque为stack初始化时deque可省  因为stack是基于deque实现的, 默认以deque方式构造
   deque<int> d1 = {1,2,3,4,5};
   stack<int,deque<int>> s3(d1);
   stack<int> s4(d1);

   //4、用list容器初始化stack
   list<int> l1 = {1,2,3,4,5};
   stack<int,list<int>> s5(l1);


   s.push(2);
   s.push(3);
   s.push(4);

   int e = 1;
   //元素ele入栈，增加元素 O(1)
   s.push(e);
   //移除栈顶元素 O(1)
   s.pop();
   //取得栈顶元素（但不删除）O(1)
   s.top();
   //检测栈内是否为空，空为真 O(1)
   s.empty();
   //返回栈内元素的个数 O(1)
   s.size();

   system("pause");
   return 0;
}
