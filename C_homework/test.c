
#include <stdio.h>
#include<string.h>
int main()
{
int n,i;
char ch;
double a;
double celsius,fahr;
scanf("%d\n",&n);

for (i=0; i<n; i++)
{scanf("%c %lf",&ch,&a);
 getchar();


 if (ch=='C'){
    celsius=a*1.8+32;
  printf("%0.2lf\n",celsius);}
 else{
    fahr=(a-32)/1.8;
 printf("%0.2lf\n",fahr);}

};

  return 0;
}
