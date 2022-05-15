#include <stdio.h>
#include <stdlib.h>

struct process *newProcess(int pid, float at, float bt, int priority);
void addNewProcess(struct process *ptr);
void calculateTime();
void printQueue();

float current_at = 0, wt = 0, tat =  0;
int n;

struct process
{
    int pid, priority;
    float at, bt, wt, st, ft, tat;
    struct process *next;
} *head = NULL;

int main()
{
    int i, prority;
    float at = 0, bt;
    printf("Enter total number of processes:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter process(%d) Information.\n", i);

        printf("Burst time :");
        scanf("%f", &bt);

        printf("Enter priority:");
        scanf("%d", &prority);
        addNewProcess(newProcess(i, at, bt, prority));
    }
    calculateTime();
    printQueue();

    return 0;
}

// function to create new process
struct process *newProcess(int pid, float at, float bt, int priority)
{
        printf("TEST");

    struct process *ptr = (struct process *)malloc(sizeof(struct process));

    ptr->pid = pid, ptr->at = at, ptr->bt = bt, ptr->priority = priority;
    ptr->wt = -1, ptr->tat = -1, ptr->ft = -1;
    ptr->next = NULL;

    return ptr;
}

void addNewProcess(struct process *ptr)
{
    struct process *parent = NULL, *i;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        for (i = head; i != NULL && i->priority <= ptr->priority; i = i->next)
            parent = i;

        if (parent == NULL)
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

void printQueue()
{
    struct process *ptr;
    printf("\nProcesses\n");
    printf("pid\t  AT  \t  ST  \t  BT  \t  WT  \t  FT  \t TAT  \tPriority\n");
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        printf("%d\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%d\n", ptr->pid, ptr->at, ptr->st, ptr->bt, ptr->wt, ptr->ft, ptr->tat, ptr->priority);

    printf("\nAWT :%f\n", wt/n);
    printf("\nATAT :%f\n", tat/n);


}

void calculateTime()
{
    struct process *i;
    for(i = head; i != NULL; i=  i->next)
    {
        i->st = current_at;
        i->ft = i->st + i->bt;
        i->wt = i->st - i->at;
        i->tat = i->ft - i->at;
        current_at += i->bt; 
        wt += i->wt;
        tat += i->tat;
    }
}
