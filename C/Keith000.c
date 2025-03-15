#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch[] = "12+29";
	int i = 0;
	int a = 0, b = 0;
	int result = 0;
	while('0'<=ch[i] && ch[i]<='9'){
		a = a * 10 + (ch[i] - '0');  //ch[i] - '0' 转化成int型数
		i++;
	}

	char op = ch[i];
	i++;

	while('0'<=ch[i] && ch[i]<='9'){
		b = b * 10 + (ch[i] - '0');
		i++;
	}

	switch(op){
		case '+':
			result = a + b;
			break;
		default:
			printf("error!\n");
	}
	printf("%d\n", result);

	system("pause");
	return 0;
}