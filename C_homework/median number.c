#include<stdio.h>
#include<string.h>
#include<math.h>

void swap(int *A, int i, int j){
    int temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;

}

void sort(int *A, int str, int end){
    int i,j,temp;
    for(i=str;i<end;i++){
        j=i-1;
        temp=A[i];

        while(A[j]>temp && j>=0){
            swap(A,j,j+1);
            j--;
        }
    }
}

void calcul(int *A, int end){
    float d;
    if( end%2 != 0)
        d=A[(end)/2];
    else
        d=(double)(A[(end/2)-1]+A[(end/2)])/2;
    printf("%.1f\n",d);
}

void median(){
    int A1[500]={0};
    int A2[500]={0};
    int A[1000]={0};
    int m,n,p,i,j,k;
    int md;

    scanf("%d %d\n",&m,&n);

    for (i=0;i<m;i++){
        scanf("%d",&A1[i]);
    }

    for(j=0;j<n;j++){
        scanf("%d",&A2[j]);
    }
//录入数组
    p=m+n;

    for(k=0;k<m;k++){
        A[k]=A1[k];
    }

    for(k=m;k<p;k++){
        A[k]=A2[k-m];
    }
//数组合并


    sort(A,m,p);
    calcul(A,p);

}

int main(){
    int N,i;
    scanf("%d",&N);
    for (i=0;i<N;i++){
        median();
    }

    return(0);

}

