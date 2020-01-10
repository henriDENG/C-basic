#include<stdio.h>
#include<math.h>
#include<string.h>


int somme()
{char ch;
char s1[1000],s2[1000];
int a[1000]={0},b[1000]={0},m,n,c,k,i,j;

int v=0,l=0;

scanf("%c",&ch);
while (ch != ' ')
{s1[v]=ch;
  v=v+1;
  scanf("%c",&ch);
}

scanf("%c",&ch);
while (ch !='\n' )
{
s2[l]=ch;
l=l+1;
scanf("%c",&ch);
};

m=v;
n=l;

if(m<n)
    k=n;
else
    k=m;
    c=k;

for(i=0;i<m;k--,i++)
    a[k]=s1[m-1-i]-'0';

for(k=c,i=0;i<n;k--,i++)
    b[k]=s2[n-1-i]-'0';

for(i=c;i>=0;i--)
{a[i]+=b[i];
if(a[i]>=10)
{a[i]-=10;
a[i-1]++;}
}

if(a[0]!=0)
 {for(i=0;i<=c;i++)
printf("%d",a[i]);}
else
 {for(i=1;i<=c;i++)
printf("%d",a[i]);}
printf("\n");
}

int main()
{int N,r;
  scanf("%d\n",&N);
  for (r=1;r<=N;r++)
    {
    somme();
    }
  printf("END");
  return(0);
}

