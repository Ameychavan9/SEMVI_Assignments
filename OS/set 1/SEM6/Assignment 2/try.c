#include <stdio.h>
#include <stdlib.h>

int total_itr = 1;
float io_burst = 2;


// to store process information
struct process{
	int pid, ino;
	float *at, *bt, *st, wt, ft, tat;
	struct process *next, *pre;
}*jobQueueFront = NULL;

// to store process execuation sequence
struct p_seq{
	struct process *p;
	struct p_seq *next, *pre;
}*seq_front = NULL, *seq_rear = NULL;


struct process *newProcess(int);
void addToJobQueue(struct process *);
struct process *pop_process(struct process *);
void printQueue(struct process *);
void sjf_algo();



int main()
{
	int n, i;
	struct p_seq *seq_itr;
	printf("How many process are there :");
	scanf("%d", &n);

	
	for(i = 0; i < n; i++)
	{

		addToJobQueue(newProcess(i));
	}

	printQueue(jobQueueFront);
	sjf_algo();

	for(seq_itr = seq_front; seq_itr != NULL; seq_itr->next)
	{
		printf("%d", seq_itr->p->pid);
	}

	

}


// function to create new process with data provided
struct process *newProcess(int pid)
{
	int i = 0;	
	struct process *new_process = (struct process *)malloc(sizeof(struct process));
	new_process->pid = pid, new_process->ino = -1, new_process->wt = 0, new_process->ft = 0,new_process->tat = 0;
	new_process->next = NULL, new_process->pre = NULL;

	new_process->at = (float *)malloc(sizeof(float) * total_itr);
	new_process->bt = (float *)malloc(sizeof(float) * total_itr);
	new_process->st = (float *)malloc(sizeof(float) * total_itr);

	printf("\nEnter arrival time :");
	scanf("%f", &new_process->at[0]);
	
	printf("Enter Burst time for each iteration.\n");
	for(i = 0; i < total_itr; i++)
	{
		printf("Enter burst time (%d)", i+1);
		scanf("%f", &new_process->bt[i]);
	}
	return new_process;
}


// function to crate a jobqueue sorted according to arrival time
void addToJobQueue(struct process *ptr)
{
	struct process *i, *parent;

	ptr->ino++; // incrementing iteration count of process 

	if(jobQueueFront == NULL)
		jobQueueFront = ptr;
	else
	{
		for(i = jobQueueFront; i != NULL; i = i->next)
		{
			if(i->at[i->ino] > ptr->at[ptr->ino])
				break;
			parent = i;
		}

		if(jobQueueFront->at[jobQueueFront->ino] > ptr->at[ptr->ino]) // if new process has less arrival time then first process
		{
			jobQueueFront->pre = ptr;
			ptr->next = jobQueueFront;
			jobQueueFront = ptr;
		}
		else // else appending new process to parent
		{
			ptr->next = parent->next;
			if(ptr->next != NULL)
				ptr->next->pre = ptr;
			ptr->pre = parent;
			parent->next = ptr;
		}		

	}
	
}

void printQueue(struct process *ptr)
{
	struct process *i;
	printf("\nQueue:");
	for(i = ptr; i != NULL; i = i->next)
		printf("p%d->", i->pid);
	printf("\n");
}

// to add process to completed seqence
void addToSeq(struct process *ptr)
{
	struct p_seq *new_seq= (struct p_seq *)malloc(sizeof(struct p_seq));
	new_seq->next = NULL;
	new_seq->pre = NULL;
	if(seq_front == NULL)
	{
		seq_front = new_seq;
		seq_rear = seq_front;
	}
	else
	{
		new_seq->pre = seq_rear;
		seq_rear->next = new_seq;
		seq_rear = seq_rear->next;
	}
	
}

// function to pop out process from a queue
struct process *pop_process(struct process *ptr)
{
	if(ptr->pre != NULL)
		ptr->pre->next = ptr->next;
	else
		jobQueueFront = ptr->next;

	if(ptr->next != NULL)	
		ptr->next->pre = ptr->pre;
	return ptr;
}

// function to perform sjf algorithum on process queue
void sjf_algo()
{
	struct process *ptr = jobQueueFront, *min = NULL;
	
	float current_at = 0, temp_bt;

	do
	{		printf("\nmin :%d", min->pid);
		temp_bt = ptr->bt[ptr->ino];

		while(ptr != NULL && ptr->at[ptr->ino] <= current_at)
		{
			if(ptr->bt[ptr->ino] <= temp_bt)
			{
				min = ptr;
				temp_bt = min->bt[min->ino];
			}
			ptr = ptr->next;
	
		}

		if(min == NULL)
		{
			min = jobQueueFront;
			current_at = min->at[min->ino];
		}

		min = pop_process(min);
		ptr = jobQueueFront;
		addToSeq(min);
		current_at += min->bt[min->ino];

		if(min->ino < total_itr -1)
		{
			min->at[min->ino + 1] = current_at + io_burst;
			addToJobQueue(min);
		}
		min = NULL;

	}while(ptr != NULL);

}









































