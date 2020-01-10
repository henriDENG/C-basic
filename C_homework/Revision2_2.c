#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int a,i,n=0;

    while(1){
        scanf("%d",&a);

        for (i=1; i<= sqrt(a);i++){
            if (a%i == 0 && i!= sqrt(a))
                n=n+2;
            else if (a%i ==0 && i == sqrt(a))
                n=n+1;

        }

        printf("%d\n",n);
        n=0;
    }




    return 0;
}
