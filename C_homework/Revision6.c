#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

int swap(char *str, int start ,int end)
{
    char temp;
    char *a,*b;//ע�⺯���ڱ������͵��ñ���һ��

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
    }//�ѿո�ǰ�Ķ���һ��
    swap(str,start,last);//���һ����һ��

}

int output(char *str)
{
    printf("%s\n",str);//��ӡ�ַ���

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
