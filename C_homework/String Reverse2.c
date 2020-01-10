#include<stdio.h>
#include<string.h>
#include<math.h>

int reverse(char* str, int start, int end){
    char*a,*b;
    char ch;

    a=str+end;
    b=str+start;

    while(a>b){
        ch=*a;
        *a=*b;
        *b=ch;
        a--;
        b++;
    }
}


int divide(char *str){
    int i;
    int start=0;
    int end;

    for(i=0;i<strlen(str)-1;i++){
        if(str[i]==' '){
            end=i-1;
            reverse(str,start,end);
            start=i+1;
        }
    }
    reverse(str,start,strlen(str)-1);//把最后一个单词反过来
}

int main(){
    int n;
    int j;
    char str[1000];

    scanf("%d\n",&n);

    for(j=0;j<=n-1;j++){
        gets(str);
        divide(str);
        printf("%s\n",str);
    }
    return 0;
}


