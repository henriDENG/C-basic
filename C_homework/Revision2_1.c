#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{

    int n,i=0;
    char ch;
    float a;

    scanf("%d\n",&n);

    for (i=0; i<n; i++){
        scanf("%c %f",&ch,&a);
        getchar();  //manger '\n'

        if(ch == 'C'){
            printf("%.2f\n",a*1.8+32);
        }
        else if (ch == 'F'){
            printf("%.2f\n",(a-32)/1.8);
        }

    }

    return 0;

}
