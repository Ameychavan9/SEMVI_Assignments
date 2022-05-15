
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int no;
	float at,bt,wt,ft,tat,tmpbt;
	int pr;
	struct node *next;
}NODE;

int process,count=0,min;
float S_time = 0.0,idle[100];

int create_insert(NODE **p, int no, float at, float bt,int pr)
{
	NODE *q,*r=*p;
	q=(NODE*)malloc(sizeof(NODE));
	q->no=no+1;
	q->at=at;
	q->bt=bt;
	q->tmpbt=bt;
	q->pr=pr;
	q->next=NULL;

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


void calculate(NODE **p)
{
	NODE *q=*p,*r=*p;
	int c1=0,c2,min_pr;
	float min_bt;	
	
	printf("\nGANTT CHART\n\n================================================================================================\n");
	if(q->at!=0.0)
		S_time = q->at;
	else
		S_time = 0.0;

	for(;count!=process;++S_time)
	{
		q=*p;
		int counter = 0;
		min = 1000;
		for(;q!=NULL;q=q->next)
		{
			if(min>q->pr && q->at<=S_time && q->bt>0.0)
			{
				min =q->pr;
			}
			counter++;	
		}
		q=*p;
		while(q)
		{
			if(q->pr == min)
			{
				printf("|P%d",q->no);
				q->bt=q->bt-1;
				if(q->bt == 0.0)	
				{
				count++;
				q->ft=S_time +1;
				q->tat = S_time + 1 - q->at;	
				q->wt = q->tat - q->tmpbt;
				}
				break;
			}
			q=q->next;
		}
		
	}	
	printf("|\n================================================================================================");
}


void display_sort(NODE *p)
{
	NODE *r=p;
	printf("\n======================================\n| ProcessID| A.T   | B.T   | Priority |\n======================================");
	while(r)
	{
		printf("\n|  %d       |  %.2f   |  %.2f | %d	|",r->no,r->at,r->tmpbt,r->pr);
		r=r->next;
	}
	printf("\n======================================");	
}


void display_chart(NODE *p)
{
	NODE *r=p;
	printf("\n=====================================================	\n| ProcessID|   A.T   | B.T   | T.A.T | W.T   | F.T   |\n=====================================================");
	while(r)
	{
		printf("\n|  %d       |  %.2f   |  %.2f | %.2f	| %.2f   | %.2f  |",r->no,r->at,r->tmpbt,r->tat,r->wt,r->ft);
		r=r->next;
	}
}
void swap(NODE *a,NODE *b)
{

	float tmp,tmp1;
	int pno;
	pno   = a->no;
	a->no = b->no;
	b->no = pno;

	tmp   = a->at;
	a->at = b->at;
	b->at = tmp;

	tmp1  = a->bt;
	a->bt = b->bt;
	b->bt = tmp1; 
	
	pno   = a->pr;
	a->pr = b->pr;
	b->pr = pno;
}

void sorting(NODE *start)
{
	int swapped,i;
	NODE *ptr;
	NODE *lptr = NULL;
	if(start == NULL)
		return;
	do
	{
		swapped = 0;
		ptr=start;
		while(ptr->next!=lptr)
		{
			if(ptr->at > ptr->next->at)
			{
				swap(ptr,ptr->next);
				swapped=1;
			}
			ptr=ptr->next;
		}
	}while(swapped);
}

void display(NODE *p, int process){
	float ttat, twt, tbt;
	ttat = twt  = tbt = 0;
	printf("\n\n\nProcess Details:");
	while(p!=NULL){
	printf("\n ProcessID       :  %d", p->no);
	printf("\n Arrival Time    :  %.2f", p->at);
	printf("\n Burst Time      :  %.2f", p->tmpbt);
	printf("\n Turn Around Time:  %.2f", p->tat);
	printf("\n Waiting Time    :  %.2f", p->wt);
	
	printf("\n =================================\n");
	ttat+=p->tat; 
	twt+=p->wt;
	tbt+=p->tmpbt;

	p=p->next;

}

printf("\n\n\n OVERALL DETAILS : \n ");
printf("\n\n Throughput : %.2f",process/tbt);
printf("\n Avergae Waiting Time: %.2f\n", twt/process);
printf("\n Average Turn Around Time: %.2f\n", ttat/process);
printf("\n ========================================\n ");
}

	
/// Main Program 

void main(){
	NODE *head=NULL;
	char ch;
	int  i=0,j,k,pr;
	float arr_time, burst_time;

	do
	{	
		printf(" <== Enter Process Details ==> ");
		printf("\n\tArrival Time: ");
		scanf("%f",&arr_time);
		printf("\n\tBurst Time: ");
		scanf("%f",&burst_time );
		printf("\n Enter the Priority ==> ");
		scanf("%d",&pr);
		create_insert(&head,process,arr_time,burst_time,pr);
		process++;
		printf("\n Is there any other process (Y/N) ==> ");
		scanf("%d",&i);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	
	printf("\t PROCESS LIST \n");
	display_sort(head);
	sorting(head);
	
	printf("\n\n\t PROCESS SCHEDULED AS  \n");
	display_sort(head);
	calculate(&head);
	display_chart(head);	
	display(head,process);
	printf("\n<-------------------------------END---------------------------->\n");

}	
