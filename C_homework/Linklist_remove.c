#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

typedef struct num{
    int val;
    struct num *next;
}NUM;

typedef NUM* NUMPTR;


int input(NUMPTR *p, int *ref)
{
    NUMPTR q = NULL;
    int l=0;
    char c;
    *ref=0; //��ʼ��

    c=getchar();

    while (c != ' '){
        if(*p == NULL){
            (*p)=(NUMPTR)malloc(sizeof(NUM));
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

        l++;
        c=getchar();
    }    //�ַ�������

    scanf("%d", ref);  //�����βλ��

    return l;   //�ܳ���

}


NUMPTR jumpto(NUMPTR p, int pos) //��pλ��ָ��
{   int i=0;

    while (i<pos && p!= NULL){
        p=p->next;
        i++;
    }

    return p;

}


int remove_ref(NUMPTR *p, int ref, int total)
{   int i;
    int pos;
    NUMPTR q=NULL, v=NULL; //��ʼ��

    pos=total-ref-1;
    q=*p;
        if(total > 1){
            if (ref != 0 &&  ref != total  && q != NULL){
                q=jumpto(q,pos);
                //printf("%d\n",q->val);
                v=q->next;
                // printf("%d\n",v->val);
                q->next=v->next;
            }
            else if (ref == total && q != NULL){
                *p=q->next;
            }
        }

}


void output(NUMPTR p)
{
    while(p != NULL){
        printf("%d",p->val);
        p=p->next;
    }

    printf("\n");
}


int main()
{
    int N;
    int j;
    scanf("%d\n",&N);

    for (j=0;j<N;j++){

        NUMPTR a = NULL;
        int reff;
        int length_a;

            length_a = input(&a, &reff);
            getchar();
            remove_ref(&a, reff, length_a);
            if (length_a == 1 && reff !=0){
                printf("0\n");
            }
            else
                output(a);

    }

    return 0;

}



