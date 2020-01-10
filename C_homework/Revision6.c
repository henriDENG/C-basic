#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

int swap(char *str, int start ,int end)
{
    char temp;
    char *a,*b;//注意函数内变量名和调用变量一致

    a=str+start;
    b=str+end;

    while (b>a){
        temp=*b;
        *b=*a;
        *a=temp;
        b--;
        a++;
    }

}

int reverse(char *str)
{
    int j;
    int start=0;
    int last=strlen(str)-1;

    for (j=0;j<last;j++){
        if( str[j] == ' '){
            swap(str,start,j-1);
            start=j+1;
        }
    }//把空格前的都反一下
    swap(str,start,last);//最后一个反一下

}

int output(char *str)
{
    printf("%s\n",str);//打印字符串

}


int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    for (int i=0;i<n;i++){
        char str[1000]={0};
        gets(str);
        reverse(str);
        output(str);
    }

    return 0;

}
