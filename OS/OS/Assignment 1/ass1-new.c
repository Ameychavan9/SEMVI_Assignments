#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int no;
	float at,bt,st,wt,ft,tat;
	struct node *next ;
}NODE;

int process,c=0;
float S_time=0.0,idle[100];

void create_insert(NODE **p,int no,float at,float bt)
{
	NODE *q,*r=*p;
	q = (NODE*)malloc(sizeof(NODE));
	q->no=no+1;
	q->at=at;
	q->bt=bt;
	q->next= NULL;

	if(*p==NULL)
	{	
		*p=q;
	}
	else
	{
		while(r->next!=NULL)
		{
			r=r->next;
		}
		r->next=q;
	}
}

int calculate(NODE **p)
{
    NODE *q=*p,*r=*p;
    int c1=0, c2;
    printf("\n---------------------------------------------------------------------");
    printf("\n|Process |  A.T    |  B.T    |  S.T    |  W.T    |  F.T   |  T.A.T  |");
    printf("\n---------------------------------------------------------------------");

    while(q)
    {   
	c2=0;
        if(c1==0)
        {   
            if(q->at>S_time)
            {
                idle[c++]=0.0;
                idle[c++]=q->at;
                S_time=q->at;
                c2=2;
            }
            else
            {
                q->st=q->at;
                q->wt=q->at;    
                idle[c++]=q->st;
                c1++;
            }
        }
        else
        {  
		if(q->at>S_time)
		{
		        q->st=S_time + (q->at-S_time);
                	q->wt=q->st-q->at;  
		        idle[c++]=q->st;
		        idle[c++]=q->at;
	        }   
		else
		{
		        q->st=S_time;
		        q->wt=q->st-q->at;  
                	idle[c++]=q->st;
	        }
        }   

        if(c2!=2)
        {
            q->ft=q->st+q->bt;
            idle[c++]=q->ft;
            q->tat=q->ft-q->at;
            S_time=q->ft;
            printf("\n| P%d     |  %.2f   |  %.2f   |  %.2f   |  %.2f   |  %.2f  |  %.2f   |",q->no,q->at,q->bt,q->st,q->wt,q->ft,q->tat);
            q=q->next;
        }
    }
    return c;
}

void display_sort(NODE *p)
{
    NODE *r=p;
    printf("\n=================================\n|ProcessId | A.T   | B.T  |\n=================================");
    while(r)
    {
        printf("\n| P%d     |  %.2f   |  %.2f   |",r->no,r->at,r->bt);
        r=r->next;
    }
}

void swap(NODE *a,NODE *b)
{
/*    NODE *tmp;
    tmp->next=a->next;
    a->next=b->next;
    b->next=tmp->next;
  */  

    float tmp,tmp1;
    int pno;
    pno = a->no;
    a->no = b->no;
    b->no =pno;
    
    tmp = a->at;
    a->at = b->at;
    b->at =tmp;
    
    tmp = a->bt;
    a->bt = b->bt;
    b->bt =tmp;

}

void sorting(NODE *start)
{
    int swapped,i;
    NODE *ptr;
    NODE *lptr =NULL;
    if(start == NULL)
        return;
    
    do
    {
      swapped=0;
      ptr=start;
      while(ptr->next!=lptr)
      {
        if(ptr->at > ptr->next->at)
        {
            swap(ptr,ptr->next);
            swapped=1;
        }  
        ptr = ptr->next;
      }
    }while(swapped);
}

void gantt_chart(NODE *p,int process,float idle[],int c)
{
	int i,count=1;
	NODE *r=p;
	printf("\n\n GANNTH CHART:\n");
    if(c>process)
        process=c;
	for(i=1;i<process;i++)
	{
		printf("----------------");
	}	
	printf("\n");

	for(i=1;i<process;i++)
	{   
	    if(p->st==idle[i-1])
        {
            printf("|\tP%d\t",p->no);
		    p=p->next;
        }
        else{
            printf("|    IDLE  %d\t",count);
            count++;
        }
		
	}	
	printf("|\n");

	for(i=1;i<process;i++)
		printf("----------------");
	printf("\n");
	for(i=1;i<process;i++)	
	{
        if(r->st==idle[i-1])
        {
            printf("%.1f  \t\t",r->st);
		    r=r->next;
        }
        else{
            printf("%.1f  \t\t",idle[i-1]);
        }
	}	
    printf("%.1f",idle[c-1]);
}

void display(NODE *p,int process){
	float ttat,twt,trd,trt,tbt;
	ttat=twt=trd=trt=tbt=0;
	printf("\n\n PROCESS DETAILS :");
	while(p!=NULL){
	printf("\n PROCESS : %d \n",p->no);
	printf("\n ARRIVAL TIME : %.2f \n",p->at);
	printf("\n BURST TIME : %.2f\n",p->bt);
	printf("\n TURN AROUND TIME : %.2f\n",p->tat);
	printf("\n WAITING TIME: %.2f\n",p->wt);
    printf("\n ========================\n");
	ttat+=p->tat;
	twt+=p->wt;
	tbt+=p->bt;

	p=p->next;

	}

	printf("\n\n OVERALL DETAILS \n");
    printf("\n Throughput : %.2f",process/tbt);
	printf("\n Average wait time : %.2f",twt/process);
    printf("\n Average turn around time : %.2f",ttat/process);
	
}

void main()
{
	NODE *head=NULL;
	char ch;
	int i=0,j,k;
	float arr_time,burst_time,first_response,tmp;
    do
    {
	    printf("\n <== Enter process  details ==> ");
        printf("\n Arrival Time : ");
		scanf("%f",&arr_time);
		printf("\n Burst Time   : ");
		scanf("%f",&burst_time);
		create_insert(&head,process,arr_time,burst_time);
        process++;
        printf("Is there any other process (Y/N) ==> ");
        scanf("%d",&i);
        scanf( "%c",&ch);
    }while(ch=='y'|| ch=='Y');    
    printf(" \t Process list ");
    display_sort(head);
    sorting(head);
    display_sort(head); 
    c=calculate(&head);

   // removing duplicate entries
     for(i=0;i<c;++i)
    {
        for(j=i+1;j<c;++j)
        {
            if(idle[i]==idle[j])
            {
                for(k=j;k<c;k++)
                {
                    idle[k]=idle[k+1];
                }   
            j--;
            c--;
            }
        }
    }

// printf("===================START======================");
gantt_chart(head,process,idle,c);
display(head,process);

 printf("===================STOP======================");
}
