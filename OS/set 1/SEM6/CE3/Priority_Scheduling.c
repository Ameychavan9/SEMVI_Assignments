#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pid, priority;
	float at, bt, st, wt, ft, tat;
	struct process *next;		
}*head = NULL;

int n;
float current_at = 0, wt = 0, tat = 0;

struct process *newProcess(int, float, float, int);
void addNewProcess(struct process *ptr);
void printfQueue();
void calculateTime();


int main()
{
	int i, priority;
	float at = 0, bt; 
	do{
		printf("Enter total number of processes :");
		scanf("%d", &n);

		if(n < 0)
			printf("\nNumber of process can't be less than 0\n");
	}while(n < 0);
	
	printf("\nEnter processes information.\n");
	for(i = 0; i < n; i++)
	{	printf("\nFor process %d", i);
		do{
			printf("\nBurst time :");
			scanf("%f", &bt);

			if(bt < 0)
				printf("\nBurst time can't be negative.\n");
		}while(bt < 0);

		do{
			printf("Priority :");
			scanf("%d", &priority);

			if(priority < 0)
				printf("\nPriority can't be negative.\n");
		}while(priority < 0);

		addNewProcess(newProcess(i, at, bt, priority));

	}
	calculateTime();
	printfQueue();

	
}

// function to create a new process with related information
struct process *newProcess(int pid, float at, float bt, int priority)
{
	struct process *ptr = (struct process *)malloc(sizeof(struct process));
	ptr->pid = pid, ptr->at = at, ptr->bt = bt, ptr->priority = priority;
	ptr->st = -1, ptr->wt = -1, ptr->ft = -1, ptr->tat = -1;
	ptr->next = NULL;
	return ptr;	
}

// function to add newely created process in linked list(queue)
void addNewProcess(struct process *ptr)
{
	struct process *parent = NULL, *i;
	
	if(head == NULL)
	{	
		head = ptr;
	}
	else
	{
		for(i = head; i != NULL && i->priority <= ptr->priority; i = i->next)
			parent = i;

		if(parent == NULL)
		{
			ptr->next = head;
			head = ptr;
		}
		else
		{		
			ptr->next = parent->next;
			parent->next = ptr;
		}	
	}
}


// function to print process table
void printfQueue()
{
	printf("\nProcesses\n");
	struct process *i;
	printf("\n  Pid  \t  AT  \t  BT \tpriority\n");
	for(i = head; i != NULL; i = i->next)
		printf("%d\t%0.3f\t%0.3f\t%d\n", i->pid, i->at, i->bt, i->priority);

	printf("\n\nAWT :%f\n", wt/n);
	printf("ATAT :%f\n", tat/n);

}

// function to calculate all times.
void calculateTime()
{
	struct process *ptr;
	
	for(ptr = head; ptr != NULL; ptr = ptr->next)
	{
		ptr->st = current_at;
		ptr->wt = ptr->st - ptr->at;
		ptr->ft = ptr->st + ptr->bt;
		ptr->tat = ptr->ft - ptr->at;
		current_at += ptr->bt;
		wt += ptr->wt;
		tat += ptr->tat;		
	}
}





























