#include <iostream>
#include<stdio.h>
using namespace std;
typedef struct node{
    string name;
    int score;
    node* next;
}node;

node* create(node* head,string name[],int score[],int len);
void show(node* first);
bool insertNode(node* first,int location,string name,int score);
int main()
{
    int n;
    cin>>n;
    string name[n];
    int score[n];
    node* first=NULL;
    for(int i=0;i<n;i++)
        cin>>name[i]>>score[i];
    first=create(first,name,score,n);
    int location,stuScore;
    string stuName;
    cin>>location>>stuName>>stuScore;
    bool flag=insertNode(first,location,stuName,stuScore);
    if(flag == false)
        cout<<"NO"<<endl;
    else
        show(first);
    return 0;
}
node* create(node* first,string name[],int score[],int len){
    first = new node;
    first->next = NULL;
    node* rear=first;
    for(int i=0;i<len;i++){
        node* s= new node;
        s->name=name[i];
        s->score=score[i];
        s->next=NULL;
        rear->next=s;
        rear=s;
    }
    return first;
}

void show(node * first){
    node* p = first->next;
    while(p != NULL){
         cout<<p->name<<" "<<p->score<<endl;
         p=p->next;
    }
}

bool insertNode(node* first,int location,string name,int score){
   int i=0;
   node* r=first;
   while(r->next!=NULL)
   {
       i++;
       if(location==i)
       {
             node* p=new node;
             p->name=name;
             p->score=score;
             p->next=r->next;
             r->next=p;
              return true;
       }
       r=r->next;
   }
   if(location==i+1)
   {
        node* p=new node;
             p->name=name;
             p->score=score;
             p->next=r->next;
             r->next=p;
              return true;
   }
   else return false;

}


