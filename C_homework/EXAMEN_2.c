#include<stdio.h>

long long int climb(int n)
{
    if(n == 1)
        return 2;
    else if (n==2)
        return 6;
    else
        return (2*climb(n-1)+2*climb(n-2));
}

int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();

    for (int j=0;j<n;j++){
        int N;
        scanf("%d",&N);
        printf("%lld\n",climb(N));
    }
    printf("END");
    return 0;
}
