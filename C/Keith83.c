#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    float coef;
    int exp;
    struct node *next;
} STU;

int main()
{
    int i = 0;
    STU *head, *p, *pre = NULL;
    do
    {
        p = (STU *)malloc(sizeof(STU));
        scanf("%f %d", &p->coef, &p->exp);
        if(i==0)
            head = p;
        if(pre!=NULL)
            pre->next = p;
        pre = p;
        i++;
    } while (getchar() != '\n');
    p->next = NULL;
    p = head;
    while(p!=NULL)
    {
        if(p!=head&&p->coef>0)
            printf("+%.1f", p->coef);
        else
            printf("%.1f", p->coef);
        if(p->exp!=0)
        {
            if(p->exp==1)
                printf("x");
            else
                printf("x^%d", p->exp);
        }
        p = p->next;
    }
    while(head){
        p = head;
        head = head->next;
        free(p);

    }
    system("pause");
    return 0;
}