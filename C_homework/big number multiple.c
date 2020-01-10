# include<stdio.h>
# include<malloc.h>

typedef struct num
{
    unsigned long int val;
    struct num *next;
}NUM;

typedef NUM* NUMPTR;

int input(NUMPTR *p) //���룬call by reference����
{
    NUMPTR q = NULL;//��ʼ��
    long int n=0;
    char c = getchar();
    while (c != '\n') {
        if (*p == NULL) {
            (*p) = (NUMPTR)malloc(sizeof(NUM));
            (*p)->val = c - '0';
            (*p)->next = NULL;
            q = *p;//ͬ�㣬ֵ���ݣ�*p�������е�ַ
        }
        else {
            q->next = (NUMPTR)malloc(sizeof(NUM));
            q = q->next;
            q->val = c - '0';
            q->next = NULL;
        }
        n++;
        c = getchar();
    }

    return n;
}


NUMPTR jumpto(int n, NUMPTR p)//���ص�n������ָ��
{
    long int i=0;
    while(i<n && p!= NULL)
    {
        p=p->next;
        i++;
    }
    return p;
}

void produit(NUMPTR a, NUMPTR b, NUMPTR *c, int na, int nb) // ��tmd��
{
    NUMPTR p,q=NULL;
    long int i,j;
    p=*c=(NUMPTR)malloc(sizeof(NUM));
    p->val=0;
    p->next=NULL;   //�������ǣ���
    i=0;
    while(i<(na+nb-1)) //��ʼ���±�
    {
        p->next=(NUMPTR)malloc(sizeof(NUM));
        p=p->next;
        p->val=0;
        p->next=NULL;
        i++;

    }
    for(i=0;i<na;i++)//����վ�����ӵ�
    {
        for(j=0;j<nb;j++)
        {
            jumpto(i+j+1,*c)->val+=jumpto(i,a)->val*jumpto(j,b)->val;
        }
    }
    for(i=0;i<na+nb-1;i++)//����λ��max��na,nb)���㹻
    {
        q=*c;
        p=(*c)->next;
        while(p != NULL)
        {
            if(p->val>9)
            {
                q->val+=p->val/10;
                p->val=p->val%10;
            }
            q=p;
            p=p->next;
        }
    }

}


void print(NUMPTR p)//���
{

    if(p->val!= 0)//��һλ����0ȫ�����
    {
        while(p != NULL){
            printf("%d", p->val);
            p=p->next;
        }
    }

    else if(p->val == 0)//��һλ��0�������
    {
        p=p->next;
            if(p->val ==0) //�ڶ�λҲ��0
            printf("0");

            else{
                while(p != NULL)//�ڶ�λ����0
                {
                printf("%d",p->val);
                p=p->next;
                }
            }
    }
    printf("\n");
}

int main()
{
    int N;
    int j;
    scanf("%d\n",&N);

        for(j=0;j<N;j++){
            NUMPTR a = NULL, b = NULL, c = NULL;
            int na,nb;

                na=input(&a);
                nb=input(&b);
                produit(a,b,&c,na,nb);
                print(c);
        }

    return 1;
}
