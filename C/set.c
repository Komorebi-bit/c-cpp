#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	void pr(char c[][100],int num,FILE *g,int x);
	FILE *f,*g;
	f=fopen("listin.txt","r");
	g=fopen("listout.txt","w");
	int i=1,num,x;
	char c[100][100];
	while (!feof(f))
	{
		fgets(c[i], 100, f);
		i++;
	}
	scanf("%d",&num);//冒号位置
	for(x=1;x<i;x++)
		pr(c,num,g,x);//输出
	fclose(f);
    fclose(g);
    return 0;
}
void pr(char c[][100],int num,FILE *g,int x)
{
	int i=0,count=0,j,k=0;
		while(c[x][k]==' '||c[x][k]=='\t')//去掉开始的空格和水平制表符
			k++;
		for( i=k;i<100;i++)
		{
			if(c[x][i]=='\0')
				break;
			if(c[x][i]==':')
			{
				for(j=count+1;j<num;j++)
					fprintf(g," ");//补齐冒号之前的空格
				fprintf(g,"%c",c[x][i]);
				c[x][i]=' ';//将冒号位置重置为空格，执行下面去掉多余空格的语句后一定会保证冒号右边只输出一个空格
				i--;
				continue;
			}
			while((c[x][i]=='\t'||c[x][i]==' ')&&(c[x][i+1]=='\t'||c[x][i+1]==' '))//去掉两个单词之间多余空格和水平制表符
				i++;
			if(c[x][i]=='\t')
			{
				fprintf(g," ");
				count++;
				continue;
			}
			fprintf(g,"%c",c[x][i]);
			count++;
		}
}