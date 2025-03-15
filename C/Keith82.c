#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    int score;
    struct node *next;
} STU;

int main()
{
    STU *p, *q, *r, *s;
    int i;
    p = (STU *)malloc(sizeof(STU));
    q = (STU *)malloc(sizeof(STU));
    r = (STU *)malloc(sizeof(STU));
    scanf("%d,%d", &p->num, &p->score);
    scanf("%d,%d", &q->num, &q->score);
    scanf("%d,%d", &r->num, &r->score);
    p->next = q;
    q->next = r;
    r->next = NULL;
    s = p;
    for (i = 0; i < 3;i++)
    {
        printf("[%d,%d]", s->num, s->score);
        s = s->next;
    }
    free(p);
    free(q);
    free(r);
    system("pause");
    return 0;
}