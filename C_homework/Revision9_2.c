#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>

void push(int*,int*,int);
void pop(int*, int*);
int rail(int*,int);

void push(int* A, int* sp, int i)
{
    A[++(*sp)]=i;
}

void pop(int* A, int *sp)
{
    A[(*sp)--]=0;
}

int rail(int* ref, int n)
{
    int stack[100]={0};
    int j=0;//ref
    int sp=-1;

    for(int k=1;k<=n;k++){
        push(stack,&sp,k);
        while(j<n && stack[sp]==ref[j]){
            pop(stack,&sp);
            j++;
        }
    }

    if (sp == -1 )
        return 1;
    else
        return 0;

}

int main()
{
    int n;
    int ref[100]={0};

    scanf("%d",&n);

    while(n != 0){
        scanf("%d",ref);
        while (ref[0] !=0 ){
            for(int k=1;k<n;k++){
                scanf("%d",ref+k);
            }
            if (rail(ref,n) == 1)
                printf("Yes\n");
            else
                printf("No\n");
            scanf("%d",ref);
        }
        printf("---\n");

        for(int k=0;k<n;k++){
            ref[k]=0;
        }

        scanf("%d",&n);
    }
    return 0;

}
