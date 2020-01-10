#include<stdio.h>
#include<string.h>
#include<math.h>

void swap(int* A, int i, int j){
    int temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;

}

int jump(int* A, int start, int end){
    int i,j;
    int pivo = A[start];
    i=start;
    j=end;

    while(i < j)
        while(A[j]>pivo){
            j--;
        }
        swap(i,j);
        while (A[i]<pivo){
            i++;
        }
        swap(i,j);









}
