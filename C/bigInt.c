#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[50] = {0}, b[50] = {0}, c[50] = {0};
    gets(a);
    gets(b);
    int len_a = strlen(a);
    int len_b = strlen(b);

    //添加正负号
    if(a[0]!='-'){
        for (int i = len_a; i > 0;i--)
            a[i] = a[i - 1];
        a[0] = '+';
        len_a++;
    }
    if(b[0]!='-'){
        for (int i = len_b; i > 0;i--)
            b[i] = b[i - 1];
        b[0] = '+';
        len_b++;
    }

    int len_min = len_a < len_b ? len_a : len_b;
    int len_max = len_a > len_b ? len_a : len_b;

    // puts(a);
    // puts(b);

    //逆置
    char t = '0';
    for (int i = 1, j = len_a - 1; i < j;i++,j--){
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    for (int i = 1, j = len_b - 1; i < j;i++,j--){
        t = b[i];
        b[i] = b[j];
        b[j] = t;
    }
    // puts(a);
    // puts(b);

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
        if(a[i]!='\0'){
            while(i<len_max){
                t = y + a[i]-'0';
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
        }
        if(b[i]!='\0'){
            while(i<len_max){
                t = y + b[i]-'0';
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
        }

        puts(c);
        printf("%c", c[0]);
        i--;
        while(i>0){
            printf("%c", c[i]);
            i--;
        }
    }


    system("pause");
    return 0;
}