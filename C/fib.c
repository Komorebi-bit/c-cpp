#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add_signed(char*);
void reverse(char *);
void big_add(char*, char*, char*);
void fib(int);

int main()
{
    int n = 0;
    scanf("%d", &n);
    fib(n);
    system("pause");
    return 0;
}

void fib(int n)
{
    if(n==1 || n==2){
        printf("1");
        return;
    }

    char a[5000] = "1", b[5000] = "1", c[5000] = "";

    for (int i = 3; i <= n;i++){
        big_add(a, b, c);
        strcpy(a, b);
        strcpy(b, c);
    }
    int iiiii = strlen(c);
    puts(c);
    printf("-------------------%d位---------------------\n", iiiii);

    return;
}

void big_add(char *a, char *b, char *c)
{

    //添加正负号
    add_signed(a);
    add_signed(b);

    int len_a = strlen(a);
    int len_b = strlen(b);

    int len_min = len_a < len_b ? len_a : len_b;
    int len_max = len_a > len_b ? len_a : len_b;

    //逆置
    reverse(a);
    reverse(b);

    //加法
    if(a[0]==b[0]){
        c[0] = a[0];
        int t=0,x=0,y=0,i=0;
        for (i = 1; i < len_min; i++){
            t = y + a[i] - '0' + b[i] - '0';
            x = t % 10;
            y = t / 10;
            c[i] = x + '0';
        }

        char *p = NULL;
        if(a[i]!='\0'){
            p = a;
        }
        if(b[i]!='\0'){
            p = b;
        }

        while(i<len_max){
            t = y + p[i]-'0';
            x = t % 10;
            y = t / 10;
            c[i] = x + '0';
            i++;
        }
        if(!y){
             c[i] = '\0';
        }else{
            c[i] = y + '0';
            i++;
            c[i] = '\0';
        }
        reverse(a);
        reverse(b);
        reverse(c);
    }

}

void add_signed(char* arr)
{
    if(arr[0] == '-' || arr[0] == '+')
        return;
    for (int i = strlen(arr)+1; i > 0;i--) //// '\0'复制过去
        arr[i] = arr[i - 1];
    arr[0] = '+';
}

void reverse(char* arr)
{
    char t = '0';
    for (int i = 1, j = strlen(arr) - 1; i < j;i++,j--){
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}