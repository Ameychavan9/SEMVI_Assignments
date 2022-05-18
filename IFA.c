#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct direct_entry{
    char filename[11];
    int indx,length;
    int *indxb;
    struct direct_entry *next;
}DR;

int *BIT,n;
int check(DR *p,char *fl)
{
    if(p==NULL)
        return 1;
    while(p)
    {
        if(strcmp(p->filename,fl)==0)
            return 0;
        p=p->next;
    }
    return 1;
}

void create_insert(DR **p,char *fl,int nb){
DR *q,*r=*p;
int i,count=0;
q = (DR*)malloc(sizeof(DR));
strcpy(q->filename,fl);
q->length=nb;
q->indxb=(int*)malloc(nb*sizeof(int));
    for(i=0;i<n && count!=nb+1;++i)
    {
        if(BIT[i]==1)
        {
            BIT[i]=0;
            if(count==0)
                q->indx=i;
            else
                q->indxb[count-1]=i;
            count++;
        }
    }    
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

void display(DR *p)
{
    DR *q=p;
    printf("\n========================================\n| FILENAME |    INDEX    | LENGTH \t|\n========================================");
    while(q)
    {
        printf("\n| %s  |\t%d\t|\t%d\t|",q->filename,q->indx,q->length);
        q=q->next;
    }
    printf("\n========================================");
}

int delete(DR **p,char *fl)
{   int i;
    DR *q=*p,*prev;
    if(q!=NULL && (strcmp(q->filename,fl))==0)
    {
        *p=q->next;
        BIT[q->indx]=1;
        for(i=0;i<q->length;++i)
            BIT[q->indxb[i]]=1;
        free(q);
        return 0;
    }
    while(q!=NULL && (strcmp(q->filename,fl))!=0) 
    {
        prev = q;
        q=q->next;
    }
    if(q==NULL)
        return -1;

    for(i=0;i<q->length;++i)
    {
        BIT[q->indx]=1;
        for(int i=0;i<q->length;++i)
            BIT[q->indxb[i]]=1;
        free(q);
    
    }  
    prev->next=q->next;
    free(q);
    return 0;
}

void main()
{
    DR *head = NULL;
    char fl[11];
    int i,c,nb,c1,AB=0,FB=0,sb;
    printf("\n Enter the size of Bit Vector (greater than 0) ==> ");
    scanf("%d",&n);
    while(n<0)
    {
        printf("\n Re-Enter the size of BIT vector as you must have entered value less than 0 ==> ");
        scanf("%d",&n);
    }
    FB=n;
    BIT = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;++i)
         BIT[i]=1;
    printf("\n Number of free blocks are 0");
    while(1)
    {
        printf("\n\n\t\t MENU\n\n\t 1.Show Bit Vector \n\t 2.Create New File \n\t 3.Show Directory \n\t 4.Delete File"); 
        printf("\n\t 5.Exit\n\tEnter your choice ==> ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\n\t BIT VECTOR \n\t==========\n");
                    for(i=0;i<n;++i)
                        printf("[%d] ",BIT[i]);
                    break;
            case 2: printf("\n Enter the File Name : ");
                    scanf("%s",&fl);
                    c1=check(head,fl);
                    if(c1==1)
                    {
                    printf("\n Enter the number of Blocks : ");
                    scanf("%d",&nb);
                    while(nb<=0)
                    {
                        printf("\n Re-Enter the number of Blocks as you must have entered value less than 0 ==> ");
                        scanf("%d",&nb);
                    }
                    if(!(nb+1<=FB))
                        printf("\n Allocation of blocks is not possible as this many number of blocks is not present");
                    else
                         create_insert(&head,fl,nb);
                    }
                    else    
                        printf("\n File with the same name is already present in the list.");
                    break;
            case 3: display(head);
                    break;
            case 4: printf("\n Enter the file name to be deleted : ");
                    scanf("%s",&fl);
                    sb=delete(&head,fl);
                    if(sb==-1)
                        printf("\n File was not present in the directory");
                    else
                        printf("\n File deleted sucessfully!!");
                    break;
            case 5: exit(0);
                    break;
            default: printf("\n Invalid input");
        }        
        AB=0;
        for(i=0;i<n;++i)
        {
            if(BIT[i]==0)
                AB+=1;
        }
        FB=n-AB;
        printf("\n\n Number of Allocated blocks are %d ",AB);
        printf("\n Number of Free blocks are %d ",FB);
    }
}