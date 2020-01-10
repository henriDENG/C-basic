#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int N,i,j,a,number,flag;
    long long int low,high,bd,var;
    char c;
    low=-2147483648;
    high=2147483647;
    bd=2147483648;
    flag=1;

    scanf("%d\n",&number);
//9223372036854775808,8085774586302733229,2147483648,8463847412 特殊值
    for(j=0;j<number;j++){

        N=0;
        a=1;
        i=0;
        flag=1;

        while((c=getchar()) != '\n'){

            if(N<=high+1){
                if(c != '-'){
                    var=(int)(c)-48;
                    N=N+var*a;
                    i=i+1;
                        if (i<=10)
                            a=a*10;
                        else if(i>10 && var!=0)
                            N=0,a=0;  //位数超界归零
                        else
                            a=0; //类似1000100000000000000的数
                }

            else
                flag=-1; //符号位
            }
        }

        if (low<=N && N<=high)
            printf("%lld\n",flag*N);

        else if (N==bd && flag==-1)
            printf("%lld\n",flag*N);

        else if (N==bd && flag==1)
            printf("%d\n",0);

        else
            printf("%d\n",0);
    };

    return 0;

}
