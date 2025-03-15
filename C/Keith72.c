#include<stdio.h>
#include<string.h>
#define  MAXN  20

void  strmcpy(  char  *t,  int  m,  char  *s  );

int  main()
{
        char  t[MAXN],  s[MAXN];
        int  m;

        gets(t);
        scanf("%d",  &m);
        strmcpy(  t,  m,  s  );
        printf("%s\n",  s);

        return  0;

}


/*函数strmcpy将输入字符串char  *t中从第m个字符开始的全部字符复制到字符串char  *s中.
若m超过输入字符串的长度，则结果字符串应为空串。*/
void  strmcpy(  char  *t,  int  m,  char  *s  )
{
    int i = 0,j=0;
    int len = strlen(t);
    if(m>len)
        s ="0";
    else
    {
        for (i = m - 1; i <= len;i++)
        {
            s[j++] = t[i];
        }
    }

    // int i, j;
	// i = m - 1, j = 0;
	// while ( t[i] != '\0' ) //遍历字符串的另一种方式 '\0'
	// 	s[j++] = t[i++];
	// s[j] = '\0';

}