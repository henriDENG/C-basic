#include<stdio.h>
#include<string.h>
#include<math.h>

void sort(int *A, int *A1, int *A2, int l1, int l2){
    int i=0,j=0,k=0;

    for(k=0;k<(l1+l2);k++){
       if (i<l1 && j<l2){
            if (A1[i]<=A2[j]){
            A[k]=A1[i];
            i++;
            }

            else if (A2[j]<A1[i]){
                A[k]=A2[j];
                j++;
            }
        }

        else if (i>=l1 && j<l2){
            A[k]=A2[j];
            j++;
        }

        else if(j>=l2 && i<l1){
            A[k]=A1[i];
            i++;
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
    int m,n,i,j,k,p;

    scanf("%d %d\n",&m,&n);

    for (i=0;i<m;i++){
        scanf("%d",&A1[i]);
    }

    for(j=0;j<n;j++){
        scanf("%d",&A2[j]);
    }

    p=m+n;

    sort(A,A1,A2,m,n);
    calcul(A,p);
}

int main(){
    int N,k;
    scanf("%d\n",&N);

    for(k=0;k<N;k++){
        median();
    }

    return(0);
}

