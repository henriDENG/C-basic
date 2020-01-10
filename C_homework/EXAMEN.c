#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void swap(char *str, int start , int end)
{
    char *a,*b;
    char temp;
    a=str+start;
    b=str+end;

    while(a<b){
        temp=*a;
        *a=*b;
        *b=temp;
        a++;
        b--;
    }

}

void reverse(char *str)
{
    int l=strlen(str);
    int start=0;
    int end=l-1;

    for (int i=0;i<=end;i++){
        if(str[i] == ' '){
            swap(str,start,i-1);
            start=i+1;
        }
    }
    swap(str,start,end);

}

void output(char *str)
{
    printf("%s\n",str);
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){

        char str[1000]={0};
        gets(str);
        reverse(str);
        output(str);

    }

    return 0;
}
