
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int no;
	float at, bt,st,wt,ft,tat;
	struct node *next;
}NODE;

int process,c=0;
float S_time = 0.0,idle[100];

int create_insert(NODE **p, int no, float at, float bt)
{

/*CREATE NODE*/
//float idle[2*process-2];

	NODE *q,*r=*p;
	q=(NODE*)malloc(sizeof(NODE));
	q->no=no;
	q->at=at;
	q->bt=bt;

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


int calculate(NODE **p)
{
	NODE *q=*p,*r=*p;
	int c1=0;
	
	printf("\n\n----------------------------------------------------------");
	printf("\n|Process | A.T   | B.T   | S.T   | W.T   | F.T   | T.A.T  |");
	printf("\n----------------------------------------------------------");
	
	while(r)
	{
		if(c1==0)
		{
       		 q->st=r->at;
       	 	idle[c++]=q->st;
		c1++;
		}
		else
		{
       		 if(q->at>S_time)
         	 {
               	 	q->st=S_time+(r->at-S_time);
            		idle[c++]=q->st;
                	idle[c++]=q->at;
          	 }
       		 else
         	 {
                	q->st=S_time;
                	idle[c++]=q->st;
          	 }
	}

	q->wt=q->st-r->at;
	q->ft=q->st+r->bt;
	idle[c++]=q->ft;
	q->tat=q->ft-r->at;
	S_time=q->ft;

	printf("\n|%d   | %.2f   | %.2f   | %.2f   | %.2f   | %.2f   | %.2f   |",q->no,q->at,q->bt, q->st,q->wt,q->ft,q->tat);

	q=q->next;
	r=r->next;
	}
	printf("\n----------------------------------------------------------");
	return c;
}


void display_sort(NODE *p)
{
	NODE *r=p;
	printf("\n==============================\n|  ProcessID | A.T   | B.T   |\n==============================");
	while(r)
	{
		printf("\n|  %d       |  %.2f   |  %.2f | ",r->no,r->at,r->bt);
		r=r->next;
	}
	printf("\n=============================");	
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


void gantt_chart(NODE *p, int process,float idle[],int c)
{
	int i,count=1;
	NODE*r=p;
	printf("\n\nGannth Chart:\n");
	if(c>process)
		process = c;
	for(i=0; i<process; i++)
		printf("--------------");
	printf("\n");

	for(i=1;i<process;i++)
	{
		if(p->st == idle[i-1])
		{
		printf("|\tP%d\t", p->no);
		p=p->next;
		}
		else
		{
		printf("| Ideal %d\t",count);
		count++;
		}
     	}
	printf("|\n");

	for(i=0;i<process;i++)
		printf("--------------");
		
	printf("\n");

	for(i=1;i<process;i++)
	{
		if(r->st==idle[i-1])
		{
		printf("%.1f  \t\t",r->st);
		r=r->next;
		}
		else
		{
		printf("%.1f  \t\t",idle[i-1]);
		}
	}
		printf("%.1f",idle[c-1]);
}

void display(NODE *p, int process){
	float ttat, twt, tbt;
	ttat = twt  = tbt = 0;
	printf("\n\n\nProcess Details:");
	while(p!=NULL){
	printf("\n ProcessID       :  %d", p->no);
	printf("\n Arrival Time    :  %.2f", p->at);
	printf("\n Burst Time      :  %.2f", p->bt);
	printf("\n Turn Around Time:  %.2f", p->tat);
	printf("\n Waiting Time    :  %.2f", p->wt);
	
	printf("\n =================================\n");
	ttat+=p->tat; 
	twt+=p->wt;
	tbt+=p->bt;

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
	int  i=0,j,k;
	float arr_time, burst_time, first_response,tmp;

	do
	{	
		printf(" <== Enter Process Details ==> ");
		printf("\n\tArrival Time: ");
		scanf("%f",&arr_time);
		printf("\n\tBurst Time: ");
		scanf("%f",&burst_time );
		create_insert(&head,process,arr_time,burst_time);
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
	c=calculate(&head);
	
	// Remove duplicate values from array
	for(i=0;i<c;++i)
	{
		for(j=i+1;j<c;++j)
		{
			if(idle[i]==idle[j])
			{	
				for(k=j;k<c;++k)
				{
					idle[k]=idle[k+1];
				}
				j--;
				c--;
			}
		}
	}


	// Gantt Chart and Display function

	gantt_chart(head,process,idle,c);	
	display(head,process);
	printf("\n<-------------------------------END---------------------------->\n");

}	
