#include<stdio.h>
#include<string.h>
#include<math.h>

void swap(int*A, int i, int j){
    int temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

int partition(int*A, int left, int right){
    int i,j;
    int pivo = A[(left+right)/2];
    i= left; j = right;
    while( 1 ){
        while(A[i]< pivo){i++;}
        while(A[j]> pivo){j--;}
        if (i<=j){
            swap(A,i,j);
            j--;
            i++;
        }
        else
            break;
    }
    return i;
}

void quicksort(int* A, int start, int end){
    int i;
    if(end > start){
        i=partition(A, start, end);
    if (i-1 > start)
        quicksort(A, start, i-1);
    if(end > i)
        quicksort(A, i, end);
    }
}

float calcul(int *A, int end){
    int p;
    float d;
    p=end;

    if (p%2 == 0)
        d = A[p/2];
    else
        d = (double)(A[(p-1)/2]+A[(p+1)/2])/2;

    return(d);
}

int median(){
    int A[1000];
    int A1[500]={0};
    int A2[500]={0};
    int m,n,i,j,k,l;

    scanf("%d %d\n",&m,&n);

    for (i=0;i<m;i++){
        scanf("%d",&A1[i]);
    }

    for(j=0;j<n;j++){
        scanf("%d",&A2[j]);
    }

    for(k=0;k<m;k++){
        A[k]=A1[k];
    }

    for(k=m;k<m+n;k++){
        A[k]=A2[k-m];
    }

    l=m+n-1;

    quicksort(A,0,l);
    calcul(A,l);

    printf("%.1f\n",calcul(A,l));

    for(k=0;k<=l;k++){
        printf("%d ",A[k]);
    }

}

int main(){
    int n,i;
    scanf("%d\n",&n);

    for (i=0;i<n;i++){
        median();
    }

    return (0);

}


