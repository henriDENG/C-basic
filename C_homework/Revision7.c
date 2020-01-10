#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int sort(int* A, int* A1, int* A2, int a, int b, int c)
{
    int i=0,j=0;

    for(int k=0;k<c;k++){

        if (i<a && j<b){
            if (A1[i] <= A2[j]){
                A[k]=A1[i];
                i++;
            }

            else{
                A[k]=A2[j];
                j++;
            }
        }

        else if(i<a && j>=b){
            A[k]=A1[i];
            i++;
        }

        else if(i>=a && j<b){
            A[k]=A2[j];
            j++;
        }

    }

}

int calcul(int* A, int c)
{
    double median;

    if (c%2 != 0){
        median= (double)A[(c-1)/2];
    }
    else{
        median=(double)(A[(c-2)/2]+A[c/2])/2;
    }

    printf("%.1lf\n",median);

}

int  main()
{
    int n;
    scanf("%d",&n);
    getchar();

    for(int k=0;k<n;k++){

        int A1[100]={0};
        int A2[100]={0};
        int A[300]={0};
        int a,b,c;

        scanf("%d %d\n",&a,&b);
        c=a+b;

        for(int k=0;k<a;k++){
            scanf("%d",&A1[k]);
        }

        for(int k=0;k<b;k++){
            scanf("%d",&A2[k]);
        }

        sort(A,A1,A2,a,b,c);
        calcul(A,c);

    }

    return 0;
}
