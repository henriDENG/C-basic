#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

typedef struct num{
    int val;
    struct num* next;
}NUM;

typedef NUM* NUMPTR;

int input(NUMPTR *p)
{
    NUMPTR q=NULL;
    char c;
    long int n=0;

    c=getchar();

        while (c!= '\n'){
            if(*p == NULL){
                *p=(NUMPTR)malloc(sizeof(NUM));
                (*p)->val=c-'0';
                (*p)->next=NULL;
                q=*p;
            }
            else{
                q->next=(NUMPTR)malloc(sizeof(NUM));
                q=q->next;
                q->val=c-'0';
                q->next=NULL;
            }
            n++;
            c=getchar();
        }

    return n;
}

NUMPTR jumpto(NUMPTR p, long int n){
    int i=0;
    while (i<n && p!=NULL){
        p=p->next;
        i++;
    }

    return p;
}


void produit(NUMPTR a, NUMPTR b, NUMPTR *c, long int la, long int lb)
{   NUMPTR p=NULL, q= NULL;
    long int i,j;
    i=0;

    p=*c=(NUMPTR)malloc(sizeof(NUM));
    p->val=0;
    p->next=NULL;

    while(i<la+lb-1)
    {
        p->next=(NUMPTR)malloc(sizeof(NUM));
        p=p->next;
        p->val=0;
        p->next=NULL;
        i++;
    }

    for (i=0;i<la;i++){
        for(j=0;j<lb;j++){
            jumpto(*c,i+j+1)->val+=jumpto(a,i)->val*jumpto(b,j)->val;
        }
    }

    for (i=0;i<la+lb-1;i++){
        q=*c;
        p=q->next;

        while(p!= NULL){

            if(p->val > 9){
                q->val+=p->val/10;
                p->val=p->val%10;
            }
            q=p;
            p=p->next;

        }
}

}


void output(NUMPTR p)
{
    if (p->val != 0)
        while (p != NULL){
            printf("%d",p->val);
            p=p->next;
        }
    else if (p->val == 0){
        p=p->next;
            if (p->val != 0){
                while(p!= NULL)
                {
                printf("%d",p->val);
                p=p->next;
                }
            }
            else
                printf("0");
    }
    printf("\n");
}


int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){

        long int na,nb;
        NUMPTR a=NULL, b=NULL, c= NULL;

        na=input(&a);
        nb=input(&b);
        produit(a,b,&c,na,nb);
        output(c);
    }

    return 0;

}
