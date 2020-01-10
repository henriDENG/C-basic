#include<stdio.h>
#include<string.h>

void swap(int *A, int i, int j)
{
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

void qsort(int *A, int l, int r)
{
    int i,j,mid;
    i=l;
    j=r;
    mid=A[(l+r)/2];

    while(i<j){
        while(A[i]<mid) i++;
        while(A[j]>mid) j--;
        if(i<=j){
            swap(A,i,j);
            i++;
            j--;
        }
    }

    if(j>l) qsort(A,l,j);
    if(i<r) qsort(A,i,r);
}

int main()
{
    int A[10];
    int r=0,l=9;
    for (int k=0;k<=l;k++){
        scanf("%d",A+k);
    }
    qsort(A,r,l);

    for (int k=0;k<=l;k++){
        printf("%d ",A[k]);
    }
}
