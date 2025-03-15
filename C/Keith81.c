//结构体数组存入一元多项式
#include<stdio.h>
#include<stdlib.h>
//定义节点结构
typedef struct term
{
    float coef;//系数
    int exp;//指数
    struct term *next;
} STU;
const int N = 100;
int main()
{
    char ch;
    int i = 0, n = 0;
    STU poly[N];
    //输入多项式的系数和指数，一回车键结束
    do
    {
        //将一组系数和指数存入数组元素
        scanf("%f %d", &poly[n].coef, &poly[n].exp);
        //计数器加一
        n++;
    } while ((ch = getchar()) != '\n' && ch != EOF);
    //输出多项式每一项内容
    for (i = 0; i < n;i++)
    {
        if(i!=0&&poly[i].coef>0)
            printf("+%.1f", poly[i].coef);
        else
            printf("%.1f", poly[i].coef);
        if(poly[i].exp>0)
        {
            printf("x");
            if (poly[i].exp>1)
                printf("^%d", poly[i].exp);
        }
    }
    system("pause");
    return 0;
}