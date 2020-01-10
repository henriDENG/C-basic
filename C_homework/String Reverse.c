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

//每一小段录入数组
        while(ch != ' ' && ch!= '\n'){
            str[v]=ch;
            v=v+1;
            scanf("%c",&ch);
        }

//输出每一小段
        for(i=v-1; i>=0; i--){
            printf("%c",str[i]);
        }
        if (ch == ' ')
        printf(" ");

//初始化
        for (l=0;l<=v-1;l++){
            str[l]=0;
        }
        v=0;

//继续读入这一行&结束
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
