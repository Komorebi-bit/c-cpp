#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXN  10
#define  MAXS  20


int  max_len(  char  *s[],  int  n  );

int  main()
{
        int  i,  n;
        char  *string[MAXN];

        scanf("%d",  &n);
        for(i  =  0;  i  <  n;  i++)  {
                string[i]  =  (char  *)malloc(sizeof(char)*MAXS);
                scanf("%s",  string[i]);
        }
        printf("%d\n",  max_len(string,  n));

        return  0;
}
/*其中n个字符串存储在动态申请的存储空间中，
函数max_len应返回其中最长字符串的长度。*/
int  max_len(  char  *s[],  int  n  )
{
        int i, MaxLen=strlen(s[0]);
        for(i=0;i<n;i++)
        {
                if(MaxLen<strlen(s[i]))
                        MaxLen=strlen(s[i]);
        }
        return MaxLen;
}