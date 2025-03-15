#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct node
{
    string name;
    int score;
    node *next;
} node;

node *create(node *first, string name[], int score[], int len);
void show(node *first);
int main()
{
    int n;
    cin >> n;
    string name[n];
    int score[n];
    node* first; //只定义了一个指向node类的指针,并没有指向任何东西,为空.
    for (int i = 0; i < n; i++)
        cin >> name[i] >> score[i];
    first = create(first, name, score, n);
    show(first);
    return 0;
}
node *create(node *first, string name[], int score[], int len)
{
    first = new node;
    first->next = NULL;
    for (int i = len - 1; i >= 0; i--)
    {
        node *p = new node;
        p->name = name[i];
        p->score = score[i];
        p->next = first->next;
        first->next = p;
    }

    return first;
}

void show(node *first)
{
    node *p = first->next;
    while (p != NULL)
    {
        cout << p->name << "  " << p->score << endl;
        p = p->next;
    }
}
