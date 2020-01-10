#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int somme()
{
    int a[100]={0};
    int b[100]={0};
    int num1[100]={0};
    int num2[100]={0};
    int add[500]={0};
    char ch;
    int i=0,j=0,k;
    int l1,l2,l_short,l_long;
    int val=0;

    while( (ch=getchar()) != ' '){
        a[i++]=(int)ch-'0';
        //printf("hh%d\n",num1[i-1]);
    }

    while( (ch=getchar()) != '\n'){
        b[j++]=(int)ch-'0';
    }

    l1=i;
    l2=j;
    //printf("%d %d\n",l1,l2);

    if(l1>=l2){
        l_long=l1;
        l_short=l2;
    }
    else{
        l_long=l2;
        l_short=l1;
    }
    //printf("%d %d\n",l_long,l_short);

    if(l_long == l1){
        for (i=1;i<=l_long;i++){
            num1[i]=a[i-1];
           // printf("h%d\n",num1[i]);
        }


        for(j=l_long-l_short+1;j<=l_long;j++){
            num2[j]=b[j-l_long+l_short-1];
           // printf("hh%d\n",num2[j]);
        }        //对齐数组

    }
    else{
        for (i=1;i<=l_long;i++){
            num1[i]=b[i-1];
           // printf("h%d\n",num1[i]);
        }

        for(j=l_long-l_short+1;j<=l_long;j++){
            num2[j]=a[j-l_long+l_short-1];
          //  printf("hh%d\n",num2[j]);
        }        //对齐数组

    }

    for (k=l_long;k>=0;k--){

        if(num1[k]+num2[k]+val<10){
            add[k]=num1[k]+num2[k]+val;
            val=0;
        }

        else if(num1[k]+num2[k]+val>=10){
            add[k]=num1[k]+num2[k]+val-10;
            val=1;
        }
           // printf("hhh%d\n",add[k]);
    }       //加法运算

    if (add[0]!= 0){
        for(k=0;k<=l_long;k++){
            printf("%d",add[k]);
        }
    }
    else{
        for(k=1;k<=l_long;k++){
            printf("%d",add[k]);
        }
    }       //打印
    printf("\n");

}

int main()
{
    int n;
    scanf("%d\n",&n);

    for(int i=0;i<n;i++){
        somme();
    }
    printf("END");

    return 0;

}
