#include <stdio.h>
#include <stdlib.h>


struct process 
{
  int pid, priority;
  float at, wt, bt, st, ft, tat;
  struct process *next;
}*front = NULL, *rear = NULL;

int n;
float *bt_arr;


struct process *newNode(int, float, float, int);
void addNewNode(struct process *);
void printQueue();
struct process *getProcess(float);
void processing();
float getBurstTimeRemain();
void calculateTime();


int main()
{
	int i, priority;
	float at, bt;
	struct process *ptr;
	printf("How many process are there :");
	scanf("%d", &n);

	bt_arr = (float *)malloc(sizeof(float) * n); // to store burst time temp.

	for(i = 0; i < n; i++)
	{	
		printf("\nEnter arrival time for P%d:", i);
		scanf("%f", &at);

		printf("Enter burst time for P%d:", i);
		scanf("%f", &bt);

		printf("Enter priority for P%d:", i);
		scanf("%d", &priority);

		addNewNode(newNode(i, at, bt, priority));
		bt_arr[i] = bt;
	
	}

	printQueue();

	processing();

	calculateTime();

	for(ptr = front; ptr != NULL; ptr = ptr->next)
		printf("p%d : %f %f\n", ptr->pid, ptr->wt, ptr->tat);
}



// create new empty process
struct process *newNode(int pid, float at, float bt, int pt)
{
	struct process *n = (struct process *)malloc(sizeof(struct process));
	n->pid = pid, n->at = at, n->bt = bt, n->priority = pt;
	n->wt = 0, n->st = 0, n->ft = 0, n->tat = 0;
	n->next = NULL;
	return n;
}

// add new process at appropiate position
void addNewNode(struct process *ptr)
{
  	struct process *i, *parent = NULL;
  
	if(front == NULL)
		front = ptr;
	else
	{
		for(i = front; i != NULL && (i->at <= ptr->at); i = i->next)
			parent = i;

		if(parent == NULL)
		{
		    ptr->next = front;
		    front = ptr;
		}
		else
		{
			ptr->next = parent->next;
			parent->next = ptr;
		}
	}
  
}

// print queue
void printQueue()
{
	struct process *ptr;
	float i = 0;
	
	for(ptr = front; ptr != NULL; ptr = ptr->next)
		printf("p%d->", ptr->pid);
	printf("\b\b\n");

}

// get process with highest priority
struct process *getProcess(float current_at)
{
	struct process *ptr, *min = (struct process *)newNode(-1, 0, 0, 1000000), *temp;
	
	temp = min;
	
	for(ptr = front; ptr != NULL && ptr->at <= current_at; ptr = ptr->next)
	{
		if(ptr->priority < min->priority && bt_arr[ptr->pid] > 0)
			min = ptr;
	}

	if(temp == min)
		min = NULL;
	free(temp);
	
	return min;
}


void processing()
{
	float i;
	struct process *ptr;
	for(i = 0; getBurstTimeRemain() != 0; i++)
	{
		ptr = getProcess(i);
		
		if(ptr != NULL)
		{
			bt_arr[ptr->pid] -= 1;
			if(bt_arr[ptr->pid] == 0)
				ptr->ft = i + 1;
		}
	}
}


float getBurstTimeRemain()
{
	int i;
	float sum = 0;
	for(i = 0; i < n; i++)
		sum += bt_arr[i];
	return sum;
}

void calculateTime()
{
	struct process *ptr;
	for(ptr = front; ptr != NULL; ptr = ptr->next)
	{
		ptr->tat = ptr->ft - ptr->at;
		ptr->wt = ptr->tat - ptr->bt;
	}
}














