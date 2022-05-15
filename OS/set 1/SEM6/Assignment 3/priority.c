#include <stdio.h>
#include <stdlib.h>

struct process 
{
    int pid, priority;
    float at, wt,ft, bt, tat;
    struct process *next;
}*front = NULL;

int n;
float *bt_arr, awt = 0, atat = 0;


struct process *createProcess(int pid, float at, float bt, int priority);
void addToProcessQueue(struct process *ptr);
void printQueue(struct process *ptr);
struct process *getProcess(float current_at);
void processing();
float getBT();
void calculateTime();
void printTable();


int main()
{
    int i, priority;
    float at, bt;
    struct process *ptr;
    printf("Enter number of processes :");
    scanf("%d", &n);

    bt_arr = (float *)malloc(sizeof(float) * n);
    printf("\nEnter processes.\n");
    for(i = 0; i < n; i++)
    {

        do
        {
            printf("Arrival time (%d):", i);
            scanf("%f", &at);
            if(at < 0)
                printf("Enter valid input.");
        } while (at < 0);

        do
        {
            printf("Burst time (%d):", i);
            scanf("%f", &bt);
            if(bt < 0)
                printf("Enter valid input.");
        } while (bt < 0);

        do
        {        
            printf("Enter priority (%d):", i);
            scanf("%d", &priority);
            
            if(priority < 0)
                printf("Enter valid input.");
        } while (priority < 0);

        addToProcessQueue(createProcess(i, at, bt, priority));
        bt_arr[i] = bt;
        printf("\n");
    }
            system("clear");

    printQueue(front);

    processing();

    printTable();
}

struct process *createProcess(int pid, float at, float bt, int priority)
{
    struct process *newProcess = (struct process *)malloc(sizeof(struct process));
    newProcess->pid = pid, newProcess->priority = priority;
    newProcess->at = at, newProcess->bt = bt, newProcess->ft = -1, newProcess->tat = -1;
    newProcess->next = NULL;
}

void addToProcessQueue(struct process *ptr)
{
    struct process *parent = NULL, *i = NULL;

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

void printQueue(struct process *ptr)
{
    printf("\nQueue :");
    
    for(ptr = front; ptr != NULL; ptr = ptr->next)
        printf("P%d->", ptr->pid);
    printf("\b\b\n");
}

// function to get process with highest prority in the given arrival time
struct process *getProcess(float current_at)
{
    struct process *ptr = NULL, *high = createProcess(-1, -1, -1, 100000), *temp;
    temp = high;

    for(ptr = front; ptr != NULL && ptr->at <= current_at; ptr = ptr->next)
        if(ptr->priority < high->priority && bt_arr[ptr->pid] > 0)
            high = ptr;

    if(temp == high)
        high = NULL;
    free(temp);

    return high; 
}

void processing()
{
    float i;
    struct process *ptr, *temp;
    for(ptr = front; ptr != NULL; ptr = ptr->next)
        for(i = 0; i < ptr->bt; i++)
        printf("---");
    printf("---\n");
    for(i = 0; getBT() > 0; i++)
    {   
		temp = ptr;
        ptr = getProcess(i);


        if (ptr != NULL)
        {
            bt_arr[ptr->pid] -= 1;
            if (bt_arr[ptr->pid] == 0)
                ptr->ft = i + 1;
			if(ptr == temp)
				printf("\b\b\b   ");
            printf("p%d|", ptr->pid);
        }
        else
            printf("**|");
    }
    printf("\n");
    for(ptr = front; ptr != NULL; ptr = ptr->next)
        for(i = 0; i < ptr->bt; i++)
        printf("---");
    printf("---\n");

}

// returns sum of burst time of remaining process
float getBT()
{
    float sum = 0;
    int i = 0;
    for (i  = 0; i < n; i++)
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
        awt += ptr->wt;
        atat += ptr->tat;
    }
    awt /= n;
    atat /= n;
}

void printTable()
{
    struct process *ptr;
    calculateTime();

    printf("\nPID\tAT  \tBT  \tPrority\tWT  \tTAT  \n");
    for(ptr = front; ptr != NULL; ptr = ptr->next)
            printf("%d\t%0.3f\t%0.3f\t%3d\t%0.3f\t%0.3f\n", ptr->pid, ptr->at, ptr->bt, ptr->priority ,ptr->wt, ptr->tat);

	printf("\nAvg WT : %f", awt);
	printf("\nAvg TAT : %f\n", atat);
}
