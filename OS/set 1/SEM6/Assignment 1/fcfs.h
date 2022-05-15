#include <stdio.h>
#include <stdlib.h>


struct node 
{
  int pid;
  float at, wt, bt, st, ft;
  struct node *next;
}*front = NULL, *rear = NULL;

//global variables
float l_ft = 0, tat = 0, awt = 0;  

// create new empty node
struct node *newNode(int pid, float at, float bt)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->pid = pid, n->at = at, n->bt = bt;
	n->wt = 0, n->st = 0, n->ft = 0;
	n->next = NULL;
	return n;
}

// add new node at appropiate position
void addNewNode(int pid, float at, float bt)
{
  	struct node *ptr, *parent = NULL;
  
	if(front == NULL)
	{
		front = newNode(pid, at, bt);
		rear = front;
	}
	else
	{
		for(ptr = front; ptr != NULL && (ptr->at <= at); ptr = ptr->next)
			parent = ptr;

		if(parent == NULL)
		{
			if(front->at >= at)
			{
			    ptr = newNode(pid, at, bt);
			    ptr->next = front;
			    front = ptr;
			}
			else
			    front->next = newNode(pid, at, bt);
		}
		else
		{
			ptr = newNode(pid, at, bt);
			ptr->next = parent->next;
			parent->next = ptr;
		}
	}
  
}

// print queue
void printQueue()
{
	struct node *ptr;
	float i = 0;

	printf("\n\t**** Table ****\n");
	printf("\n\tPid \tBT \tAT \tST \tWT \n");

	for(ptr = front; ptr != NULL; ptr = ptr->next)
		printf("\t%d \t%0.1f \t%0.1f \t%0.1f \t%0.1f\n", ptr->pid, ptr->bt, ptr->at, ptr->st, ptr->wt);

	printf("\n\tAverage Waiting Time : %0.1f\n\tAverage Turn Around Time : %0.1f\n\n", awt, tat);

}

void calculateTime()
{
	struct node *ptr;
	int total_processes = 0;

	for(ptr = front; ptr != NULL; ptr = ptr->next)
	{
		
		if(ptr->at >= l_ft)
		{
			ptr->st = ptr->at;
			ptr->wt = 0;
			ptr->ft = ptr->st + ptr->bt;
			l_ft = ptr->st + ptr->bt;
		
		}
		else
		{
			ptr->st = l_ft;
			ptr->wt = ptr->st - ptr->at;
			ptr->ft = ptr->st + ptr->bt;
			l_ft = ptr->st + ptr->bt;
		}
		total_processes++;
		awt += ptr->wt;
		tat += ptr->ft - ptr->at;
	} 
	awt /= total_processes;
	tat /= total_processes; 
}


void printGanttChart()
{
	struct node *ptr;
	int i = 0;
	float j;
	printf("\n\t\t***** Gantt Chart *****\n\n\t");

	for(ptr = front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->ft; i++)
			printf("--");
		printf("---");

		if((ptr->next != NULL) && ptr->ft != ptr->next->st)
		{
			
			for(j = 0.5; j <= (ptr->next->st - ptr->ft);j += 0.5)
				printf("-");
			printf("---");
				
		}
	}
	printf("\n\t|");
	for(ptr = front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->ft; i++)
			printf(" ");
		printf("p%d", ptr->pid);
		
		for(i = 0; i < ptr->ft; i++)
			printf(" ");

		printf("|");
		if(ptr->next != NULL && ptr->ft != ptr->next->st)
		{
			for(j = 0.5; j <= (ptr->next->st - ptr->ft);j += 0.5)
				printf("**");
			printf("|");
				
		}

	}
	printf("\n\t");
	for(ptr = front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->ft; i++)
			printf("--");
		printf("---");

		if(ptr->next != NULL && ptr->ft != ptr->next->st)
		{
			for(j = 0.5; j <= (ptr->next->st - ptr->ft);j += 0.5)
				printf("-");
			printf("---");
				
		}
	}

	printf("\n\t0");

	for(ptr = front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->ft; i++)
			printf("  ");
		printf("%0.1f", ptr->ft);
		
		if(ptr->next != NULL && ptr->ft != ptr->next->st)
		{
			for(j = 0.5; j <= (ptr->next->st - ptr->ft);j += 0.5)
				printf("  ");
			printf("%0.1f", ptr->next->st);
				
		}

	}

	printf("\n\n");

}










































  
