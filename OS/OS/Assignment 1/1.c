#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int no;
	float at, bt, pc,st,wt,ft,tat;
	struct node *next;
}NODE;
float S_time = 0.0;

void create_insert(NODE **p, int no, float at, float bt, float *fr,int c){
/*CREATE NODE*/

NODE *q,*r=*p;
q=(NODE*)malloc(sizeof(NODE));
q->no=no;
q->at=at;
q->bt=bt;
if(c==0)
{
	q->st=at;
}
else
{
	if(q->at>S_time)
		q->st=S_time+(at-S_time);
	else
		q->st=S_time;
}


q->wt=q->st-at;
q->ft=q->st+bt;
q->tat=q->ft-at;
S_time=q->ft;

//*fr=*fr+bt; //Update first Response for next NODE

/*Insert NODE at the end*/

printf("\n|%d   | %.2f   | %.2f   | %.2f   | %.2f   | %.2f   | %.2f   |",q->no,q->at,q->bt,q->st,q->wt,q->ft,q->tat);

q->next=NULL;
if(*p==NULL)
	*p=q;
else{
	while(r->next!=NULL)
		r=r->next;
	r->next=q;
    }
}

void gantt_chart(NODE *p, int process){
	int i;
	NODE*r=p;
	printf("\n\nGannth Chart:\n");
	for(i=1; i<=process; i++)
		printf("--------------------");
	printf("\n");

	for(i=1;i<=process;i++){
	printf("|\tP%d\t", p->no);
	p=p->next;
     	}
	printf("|\n");

	for(i=1;i<=process;i++)
		printf("--------------------");
	printf("\n");
	for(i=1;i<process;i++){
		printf(" %.2f  \t",r->st);
		r=r->next;
	}
		printf("\t  %.2f  \t",r->st);
		printf("\t  %.2f  \t",r->ft);
	}

void display(NODE *p, int process){
	float ttat, twt, tbt;
	ttat = twt  = tbt = 0;
	printf("\n\n\nProcess Details:");
	while(p!=NULL){
	printf("\n Process %d:\n", p->no);
	printf("Arrival Time:%.2f\n", p->at);
	printf("Burst Time:%.2f\n", p->bt);
	printf("Turn Around Time:%.2f\n", p->tat);
	printf("Waiting Time:%.2f\n", p->wt);

	ttat+=p->tat; 
	twt+=p->wt;
	tbt+=p->bt;

	p=p->next;

}

printf("\n\n\nOverall Details:\n");
printf("Avergae Waiting Time: %.2f\n", twt/process);
printf("Average Turn Around Time: %.2f\n", ttat/process);
printf("\n ====================\n ");
}
	
void main(){
	NODE *head=NULL;
	int process, i,j;
	float key,key1,key2;
	float arrival_time, burst_time, first_response,tmp;
	printf("Enter the no.of Process:");
	scanf("%d", &process);
	float A_time[process],B_time[process];
	int PI[process];
	for(i=0; i<process; i++)
	{	printf("\nEnter the Details for Process %d \n", i+1);
		PI[i]=i+1;
		printf("\tArrival Time: ");
		scanf("%f", &A_time[i]);
		printf("\tBurst Time: ");
		scanf("%f", &B_time[i]);
	}

	for(i=0;i<process;++i)
	{
		printf("%.2f",A_time[i]);
	}

	// Display all inputs
	
	printf("\n=============================");
	printf("\n|  ProcessID | A.T   | B.T   |");	
	printf("\n=============================");
	for(i=0;i<process;i++)
	{
		printf("\n|  %d       |  %.2f   |  %.2f   | ",PI[i],A_time[i],B_time[i]);
	}
	printf("\n================================================");	

	// Sorting Algo
	
	for(i=0;i<process;i++)
	{
		key=A_time[i];
		key1=B_time[i];
		key2=PI[i];
		j=i-1;
		
		while(j>=0 && A_time[j]>key){
			A_time[j+1]=A_time[j];
			B_time[j+1]=B_time[j];
			PI[j+1]=PI[j];
			j=j-1;
		}	
		A_time[j+1]=key;
		B_time[j+1]=key1;
		PI[j+1]=key2;	

	}

	// Display after sort
	for(i=0;i<process;i++)
	{
		printf("\n|  %d   |  %.2f   |  %.2f   | ",PI[i],A_time[i],B_time[i]);
	}
	printf("\n================================================");	
	
	printf("\n\n----------------------------------------------------------");
	printf("\n|Process | A.T   | B.T   | S.T   | W.T   | F.T   | T.A.T  |");
	printf("\n----------------------------------------------------------");
	for(i=0; i<process; i++)
	{

		if(i==0)
			first_response = A_time[0];
	
	create_insert(&head, PI[i] , A_time[i], B_time[i], &first_response,i);
	}

// Gantt Chart and Display function
gantt_chart(head,process);	
display(head,process);
printf("\n<-------------------------------END---------------------------->\n");

}	
