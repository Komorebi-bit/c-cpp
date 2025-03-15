#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add_signed(char*);
void reverse(char *);
void big_add(char*, char*, char*);
void fib(int);
void fib_(int);

int main()
{
    int n = 0;
    scanf("%d", &n);
    fib(n);
    fib_(n);
    system("pause");
    return 0;
}

//标准答案
void fib_(int n) {
        int MOD = 1000000007;
        if (n < 2) {
            printf("------正确答案--------%d\n", n);
            return;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q;
            q = r;
            r = (p + q)%MOD;
        }
        printf("------正确答案------%d\n", r);

}


//自己实现的
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
    printf("-------------------%u位---------------------\n", iiiii);

    unsigned int ii = 0, t = 0;
    for(int i = 1; i < strlen(c); i++){
        t = c[i] - '0';
        ii = ii * 10 + t;
    }

    printf("%u\n", ii);

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


        unsigned int ii = 0, tt = 0;
        for(int i = 1; i < strlen(c); i++){
            tt = c[i] - '0';
            ii = ii * 10 + tt;
            // printf("----%u-----数字tt\n", tt);
            // printf("----%u-----数字ii\n", ii);
        }
        ii = ii % 1000000007;

        int jj = 0, iii = 0;
        while(ii>0){
            iii = ii % 10;
            ii = ii / 10;
            c[jj++] = iii + '0';
        }
        c[jj] = '\0';
        int l = strlen(c);
        for (int i = 0, j = l - 1; i < j;i++,j--){
            int t = c[i];
            c[i] = c[j];
            c[j] = t;
        }

        puts(c);
    }

}

void add_signed(char* arr)
{
    if(arr[0] == '-' || arr[0] == '+')
        return;
    for (int i = strlen(arr)+1; i > 0;i--)  // '\0'复制过去
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