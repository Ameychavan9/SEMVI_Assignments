#include<stdio.h>
#include<stdlib.h>

int n,*PageRefStr,P,pagefault=0;

typedef struct LRU{
    int Frame;
    struct LRU *next;
}lr;
lr *start = NULL;

void List(lr **p,int i){
lr *q,*r=*p;
q = (lr*)malloc(sizeof(lr));
q->Frame=i;
q->next= NULL;
if(*p==NULL)
	*p=q;
else
{
while(r->next!=NULL)
        r=r->next;
	r->next=q;
}
}
void display(lr *p)
{
    while(p)
    {
        printf("->%d",p->Frame);
        p=p->next;
    }
}

int delete(lr **p,int i,int type)
{
    lr *q=*p,*prev;
    if(q!=NULL && q->Frame==i || type ==1)
    {
        *p=q->next;
        free(q);
        return 0;
    }
    while(q!=NULL && q->Frame!=i) 
    {
        prev = q;
        q=q->next;
    }
    if(q==NULL)
        return -1;     // try to delete node using "*r=*p"
    prev->next=q->next;
    free(q);
    return 0;
}

int check(int i)
{
    lr *q=start;
    printf("\n FRAME STACK : ");
    while(q)
    {
        if(q->Frame==i)
        {
            delete(&start,i,2);
            return 0;
        }
        q=q->next;
    }
    ++pagefault;
    return 1;
}

void lru_stack(lr **p)
{   int i,c;
    lr *q=*p;
    for(i=0;i<P;++i)
    {
        if(pagefault<n)
            c=check(PageRefStr[i]);           
        else
        {
            if((check(PageRefStr[i]))==1)
                c=delete(&start,i,1);
        }
        List(&start,PageRefStr[i]);
        display(start);
    }
}

void create()
{
    int i;
    printf("\n Enter number of pages : ");
    scanf("%d",&P);
    while(P<0)
    {
        printf("\n Re-Enter the number of pages as it should be greater than 0 : ");
        scanf("%d",&P);
    }
    PageRefStr=(int *)malloc(P*sizeof(int));
    printf("\n Enter the page reference string ==> ");
    for(i=0;i<P;++i)
        scanf("%d",&PageRefStr[i]);
    printf("\n Enter number of frames : ");
    scanf("%d",&n);
    while(n<0)
    {
        printf("\n Re-Enter the number of frames as it should be greater than 0 : ");
        scanf("%d",&n);
    }
}

void main()
{
    create();
    lru_stack(&start);
    printf("\n\nPagefault = %d",pagefault);
}