#include <stdio.h>
#include<string.h>
int main()
{
int n,i;
char ch;
double a;
scanf("%d\n",&n);

for (i=0; i<n; i++)
{scanf("%c %lf",&ch,&a);
 getchar();
 if (ch=='C')
  printf("%.2f\n",a*1.8+32);
 else
 printf("%.2f\n",(a-32)/1.8);
};

  return 0;
}



