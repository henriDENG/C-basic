#include<stdio.h>
#include<string.h>
#include<math.h>

long int reverse()
{
    char ch;
    char str[1024]={0};
    long int v=0;
    long int i,l;

    scanf("%c",&ch);
    while(ch != '\n'){

//ÿһС��¼������
        while(ch != ' ' && ch!= '\n'){
            str[v]=ch;
            v=v+1;
            scanf("%c",&ch);
        }

//���ÿһС��
        for(i=v-1; i>=0; i--){
            printf("%c",str[i]);
        }
        if (ch == ' ')
        printf(" ");

//��ʼ��
        for (l=0;l<=v-1;l++){
            str[l]=0;
        }
        v=0;

//����������һ��&����
        if(ch == ' ')
            scanf("%c",&ch);
//        else if(ch == '\n' && ch != EOF){
//
//
//          printf("\n");
//            break;
//        }
//        else
//            break;

    }


}

long int main()
{
    long int n,j;
    scanf("%d",&n);
    getchar();

    for (j=0; j<=n-1; j++){

        reverse();
         printf("\n");
    }

    return (0);
}
