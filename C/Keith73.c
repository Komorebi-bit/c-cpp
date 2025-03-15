#include  <stdio.h>
#include <stdlib.h>
//杈撳叆涓€涓鏁存暟,杈撳嚭鐩稿簲鏈堜唤鍚嶇О锛屾垨杈撳嚭wrong input!
char  *getmonth(  int  n  );

int  main()
{
        int  n;
        char  *s;

        scanf("%d",  &n);
        s  =  getmonth(n);
        if  (  s==NULL  )  printf("wrong  input!\n");
        else  printf("%s\n",  s);
        system("pause");
        return  0;
}

char  *getmonth(  int  n  )
{
        char *months[12] = {"January", "February", "March", "April", "May","June", "July","August", "September", "October", "November", "December"};
        if( n > 0 && n < 13 )
                return months[n];
        return NULL;
        /*switch(n)
        {
            case (1):return "January";
            case (2):return "February";
            case (3):return "March";
            case (4):return "April";
            case (5):return "May";
            case (6):return "June";
            case (7):return "July";
            case (8):return "August";
            case (9):return "September";
            case (10):return "October";
            case (11):return "November";
            case (12):return "December";
            default:return NULL;
        }*/
}