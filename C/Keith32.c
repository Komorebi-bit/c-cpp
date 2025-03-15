#include<stdio.h>
//三个整数排序
int main()
{
    int x,y,z,a,b,c;
    scanf("%d%d%d",&x,&y,&z);
    a=x>y?x:y;
    a=a>z?a:z;
    c=x<y?x:y;
    c=c<z?c:z;
    b = ((x != a) && (x != c)) ? x : y;
    b = b != a && b != c ? b : z;
    printf("%d %d %d",c,b,a);
    return 0;
}

