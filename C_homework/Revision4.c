#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int climb(n)
{

    if(n == 1)
        return 2;
    if(n == 2)
        return 6;
    else
        return(2*climb(n-1)+2*climb(n-2));
}

int main(void)
{
    int n,i;
    scanf("%d",&n);

    for (i=0;i<n;i++){
        int N;
        scanf("%d",&N);
        climb(N);
        printf("%lld\n",climb(N));
    }

    printf("\n");

    return 0;
}
