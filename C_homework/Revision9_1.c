#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//definition
typedef struct STRUCTNODE{
    int val;
    struct STRUCTNODE* next;
}node;
typedef node* node_PTR;

typedef struct STRUCTLINKLIST{
    node_PTR head;
    node_PTR tail;
}Linklist;
typedef Linklist* LList;


void init(LList listlink)
{
    listlink->head=(node_PTR)malloc(sizeof(node));
    listlink->head->val=0;
    listlink->head->next=NULL;
    listlink->tail=NULL;

}

int input(LList listlink, int *ref)
{
    int l=0;
    node_PTR q=NULL;
    char ch;


    ch=getchar();
    q=listlink->head;

    while(ch != ' '){
        q->next=(node_PTR)malloc(sizeof(node));
        q=q->next;
        q->val=ch-'0';
        q->next=NULL;
       // printf("hh%d\n",q->val);
        l++;
        ch=getchar();
    }

    scanf("%d",ref);
    getchar();
    //printf("hhh%d\n",*ref);

    return l;

}

void remove_List(LList listlink, int p, int length)
{
    int i;
    node_PTR q=NULL;
    node_PTR temp=NULL;
    q=listlink->head;

    if (p<length){
        for(i=0;i<p;i++){
            q=q->next;
        }

        temp=q->next;
        q->next=temp->next;
    }

}

void output(LList listlink)
{
    node_PTR p=NULL;
    p=listlink->head->next;

    while( p != NULL){
        printf("%d",p->val);
        p=p->next;
    }
    printf("\n");

}



int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){

        int ref;
        int length;
        int p;

        LList list=(LList)malloc(sizeof(Linklist));
        init(list);
        length=input(list,&ref);
        p=length-ref;
        //printf("a%d aa%d\n",length,p);
        remove_List(list,p,length);
        output(list);

    }

    return 0;
}
