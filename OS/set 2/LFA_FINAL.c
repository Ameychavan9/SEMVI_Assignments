#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct direct_entry{
    char filename[11];
    int start_block,end_block,length;
    struct direct_entry *next;
}DR;

typedef struct ll{
    int data;
    struct ll *next;
}LL;

LL *start=NULL;
int *BIT,n,end=-1;

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

void create_insert(DR **p,char *fl,int sb,int end,int nb){
DR *q,*r=*p;
q = (DR*)malloc(sizeof(DR));
strcpy(q->filename,fl);
q->start_block=sb;
q->end_block=end;
q->length=nb;
q->next= NULL;
if(*p==NULL)
	*p=q;
else
{
	while(r->next!=NULL)
	{
        r=r->next;
    }
    r->next=q;
}
}

void List(LL **p,int i){
LL *q,*r=*p;
q = (LL*)malloc(sizeof(LL));
q->data=i;
q->next= NULL;
if(*p==NULL)
	*p=q;
else
{
while(r->next!=NULL)
    {
        r=r->next;
    }		
	r->next=q;
}
}

void display(DR *p)
{
    DR *q=p;
    printf("\n=========================================================\n| FILENAME | START BLOCK | END BLOCK   |");
    printf(" LENGTH \t|\n=========================================================");
    while(q)
    {
        printf("\n| %s   |\t%d\t|\t%d\t|\t%d\t|",q->filename,q->start_block,q->end_block,q->length);
        q=q->next;
    }
    printf("\n========================================================");
}

int Allocate(int FB,char *fl,int nb)
{
    int i,count=0,sb;
    LL *q;
    for(i=0;i<n && count!=nb;++i)
	{	   
        if(BIT[i]==1)
        {
            BIT[i]=0;
            List(&start,i);
            if(count==0)
                sb=i;
            end=i;
            count++;
        }
     }	
    return sb;
}           

int delete(DR **p,LL **s,char *fl)
{
    int i;
    DR *q=*p,*prev;
    LL *cur=*s,*pr=*s,*temp;
    if(strcmp(q->filename,fl)==0)
        {
            for(i=0;i<q->length;++i)
            {
                BIT[cur->data]=1;
     		temp=cur;
	        cur=cur->next;
		free(temp);	
            } 
	*s=cur;
	}
    else{
    while(q)
    {
        if(strcmp(q->filename,fl)==0)
        {	for(i=cur->data;cur->data!=q->start_block;cur=cur->next)
			pr=cur;
            for(i=0;i<q->length;++i)
            {
                BIT[cur->data]=1;
     		temp=cur;
	        cur=cur->next;
		free(temp);	
            } 
	pr->next=cur;
	  }
        q=q->next;
    }
}
 
    q=*p;
    if(q!=NULL && (strcmp(q->filename,fl))==0)
    {
        *p=q->next;
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
    prev->next=q->next;
    free(q);    
    return 0;
}

void main()
{
    DR *head = NULL;
    char fl[11];
    int i,c,nb,sb,c1,AB=0,FB=0;
    printf("\n Enter the size of Bit Vector (greater than 0) ==> ");
    scanf("%d",&n);
    while(n<0)
    {
        printf("\n Re-Enter the size of BIT vector as you must have entered value less than 0 ==> ");
        scanf("%d",&n);
    }
    BIT = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;++i)
        BIT[i]=1;
    printf("\n Number of Allocated blocks are 0");
    FB=n;
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
                    scanf("%s",fl);
                    c1=check(head,fl);
                    if(c1==1)
                    {  printf("\n Enter the number of Blocks : ");
                        scanf("%d",&nb);
                        while(nb<0)
                        { printf("\n Re-Enter the number of Blocks as you must have entered value less than 0 ==> ");
                            scanf("%d",&nb);
                        }
                        if(nb>FB)
                            printf("This many blocks of memory is not available.\n Allocation of memory is unsucessful!! ");
                        else
                        {
                            sb=Allocate(FB,fl,nb);
                            printf("\n %d blocks are assigned to file %s ",nb,fl);
                            create_insert(&head,fl,sb,end,nb);
                        }   
                    }
                    else   
                        printf("\n File with the same name already exist");
                    break;
            case 3: display(head);break;
            case 4: printf("\n Enter the file name to be deleted : ");
                    scanf("%s",fl);
		    if(check(head,fl)){printf("\nFile Not Found\n");break;}
                    sb=delete(&head,&start,fl);
                    if(sb==-1)
                        printf("\n File was not present in the directory");
                    else
                        printf("\n File deleted sucessfully!!");
                    break;
            case 5: exit(0);break;
            default: printf("\n Invalid input");
        }        
        AB=0;
    for(i=0;i<n;++i)
        {if(BIT[i]==0)
            AB+=1;
        }
        FB=n-AB;
        printf("\n\n Number of Allocated blocks are %d ",AB);
        printf("\n Number of Free blocks are %d ",FB);
    }
}
