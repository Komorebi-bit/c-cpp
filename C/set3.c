#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	void pr(char c[][100],char d[][100],char e[][100],int num,FILE *g,int x);
	FILE *f,*g;
	f=fopen("listin.txt","r");
	g=fopen("listout.txt","w");
	int i=1,num,x;
    char c[100][100], d[100][100],e[100][100];
    while (!feof(f))
	{
		fgets(c[i], 100, f);
		i++;
	}
	scanf("%d",&num);//冒号位置
	for(x=1;x<i;x++)
		pr(c,d,e,num,g,x);//输出
	fclose(f);
    fclose(g);
    return 0;
}
void pr(char c[][100], char d[][100],char e[][100], int num,FILE *g,int x)
{
	int i=0,j=0,k=0,aa=0;
		while(c[x][k]==' '||c[x][k]=='\t')//去掉开始的空格和水平制表符
			k++;
		for( i=k;i<100;i++)
		{
			if(c[x][i]=='\0')
				break;
			if(c[x][i]==':')
			{
                aa = j;
            }
			while((c[x][i]=='\t'||c[x][i]==' ')&&(c[x][i+1]=='\t'||c[x][i+1]==' '))//去掉两个单词之间多余空格和水平制表符
				i++;
			if(c[x][i]=='\t')
			{
                d[x][j++] =' ';
				continue;
			}

            d[x][j++]=c[x][i];
        }

        int w = 0,y=0;
        for (w = 0; w < j;w++,y++)
        {
            if(d[x][w]==':'&&d[x][w-1]!=' ')
            {
                e[x][y] = ' ';
                aa = y+1;
                y++;
                e[x][y] = ':';
            }
            else if(d[x][w-1]==':'&&d[x][w]!=' ')
            {
                e[x][y] = ' ';
                y++;
                e[x][y] = d[x][w];
            }
            else
                e[x][y] = d[x][w];
        }
        int kk2, kk3;
        for (kk2 = 0; kk2 < num-aa;kk2++)
        {
            fprintf(g," ");
        }
        for (kk3 = 0; kk3 < y;kk3++)
        {
            fprintf(g,"%c",e[x][kk3]);
        }
}