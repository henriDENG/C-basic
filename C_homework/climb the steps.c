#include<stdio.h>
#include<math.h>

int main()
{
    long int stairs(long int n);
    long int n,number,i,N;
    scanf("%ld",&N);

for (i=0;i<N;i++)
{
    scanf("%ld",&n);
    number=stairs(n);
    printf("%ld\n",number);
}
    printf("END");

return 0;
}

long int stairs (long int n)
{
    long a;
    if(n==1)
        a=2;
    else if(n==2)
        a=6;
    else
        a=2*stairs(n-1)+2*stairs(n-2);
    return(a);
}
