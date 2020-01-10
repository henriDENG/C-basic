#include<stdio.h>
#include<math.h>
int main()
{long int N,i,quotient,number;
 while(scanf("%ld",&N) != EOF)
{
number=0;
  for (i=1; i<=sqrt(N); i++)
    {quotient=N%i;
       if (0==quotient && i!= sqrt(N))
          {number=number+2;}
       else if(0==quotient && i==sqrt(N))
    {number=number+1;}
    };
printf("%ld\n",number);
}
return 0;
}
