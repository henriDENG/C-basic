#include<stdio.h>
int main()
{
    char *s = {"ABC"};

    while(*s){

        printf("%d",*s%10);
        s++;
    }

    return(0);

}
