#include <stdio.h>
#include <stdlib.h>

int total_itr = 2, n;
float io_burst = 2;

// structute to store process data
struct process
{
    int pid, ino;
    float *at, *bt, *st, wt, ft, tat;
    struct process *next, *pre;
} *jobQueueFront = NULL;

// structure which can store a pointer to a process (to store process execuation sequence)
struct p_seq
{
    struct process *p;
    struct p_seq *next, *pre;
} *seq_front = NULL, *seq_rear = NULL;

struct process *newProcess(int pid)
{
    int i;
    struct process *new_process = (struct process *)malloc(sizeof(struct process));
    new_process->pid = pid, new_process->ino = -1;
    new_process->wt = 0, new_process->ft = 0, new_process->tat = 0;
    new_process->next = NULL, new_process->pre = NULL;

    new_process->at = (float *)malloc(sizeof(float) * total_itr);
    new_process->bt = (float *)malloc(sizeof(float) * total_itr);
    new_process->st = (float *)malloc(sizeof(float) * total_itr);

    printf("\nEnter arrival time :");
    scanf("%f", &new_process->at[0]);

    printf("Enter Burst time for each iteration.\n");
    for (i = 0; i < total_itr; i++)
    {
        printf("for burst (%d) :", i + 1);
        scanf("%f", &new_process->bt[i]);
    }

    return new_process;
}

// storing each process sorted according to arrival time
void addToJobQueue(struct process *ptr)
{
    struct process *i, *parent = NULL;
    ptr->ino++; // increasing iteration(visit) count
    if (jobQueueFront == NULL)
        jobQueueFront = ptr;
    else
    {
        for (i = jobQueueFront; i != NULL; i = i->next)
        {
            if (i->at[i->ino] > ptr->at[ptr->ino])
                break;
            parent = i;
        }

        if (jobQueueFront->at[jobQueueFront->ino] > ptr->at[ptr->ino])
        {
            jobQueueFront->pre = ptr;
            ptr->next = jobQueueFront;
            jobQueueFront = ptr;
        }
        else
        {
            ptr->next = parent->next;
            if (ptr->next != NULL)
                ptr->next->pre = ptr;
            ptr->pre = parent;
            parent->next = ptr;
        }
    }
}

// store sequence of process execuation
void addToSeq(struct process *ptr)
{
    struct p_seq *seq = (struct p_seq *)malloc(sizeof(struct p_seq));
    seq->p = ptr, seq->next = NULL, seq->pre = NULL;
    if (seq_front == NULL)
    {
        seq_front = seq;
        seq_rear = seq_front;
    }
    else
    {
        seq->pre = seq_rear;
        seq_rear->next = seq;
        seq_rear = seq_rear->next;
    }
}

struct process *pop_process(struct process *ptr)
{
    if (ptr->pre != NULL)
        ptr->pre->next = ptr->next;
    else // if ptr is front of job queue update front ptr
        jobQueueFront = ptr->next;

    if (ptr->next != NULL)
        ptr->next->pre = ptr->pre;

    ptr->next = ptr->pre = NULL;
    return ptr;
}

void print_seq()
{
	struct p_seq *ptr = seq_front;
    printf("\nProcess execuation sequence.\n");
    while (ptr != NULL)
    {
        printf("p%d->", ptr->p->pid);
        ptr = ptr->next;
    }

    printf("\b\b\n");
}

void sjf_algo()
{
    struct process *ptr = jobQueueFront, *min = NULL;
    float current_at = 0, temp_bt = 0;

    do
    {
        temp_bt = ptr->bt[ptr->ino];
        while (ptr != NULL && ptr->at[ptr->ino] <= current_at)
        {
            if (ptr->bt[ptr->ino] <= temp_bt)
            {
                min = ptr;
                temp_bt = min->bt[min->ino];
            }
            ptr = ptr->next;
        }

        if (min == NULL)
        {
            min = jobQueueFront;
            current_at = min->at[min->ino];
        }

        min = pop_process(min);
        ptr = jobQueueFront;
        min->st[min->ino] = current_at;
        addToSeq(min);
        current_at += min->bt[min->ino]; 

        if (min->ino < total_itr - 1)
        {
            min->at[min->ino + 1] = current_at + io_burst;
            addToJobQueue(min);
        }
        min = NULL;

    } while (ptr != NULL);
}

void calculate_time()
{
    struct p_seq *i = seq_front;
    struct process *ptr = i->p;
	float awt = 0, atat = 0, total_bt = 0;
	int j = 0, k = 0, flag = 0, p_arr[n];

	for(j = 0; j < n; j++)
		p_arr[j] = 1000000;
	
	printf("\nPID\tWT\tTAT");

    while(i != NULL)
    {
		flag = 0;
		total_bt = 0;
        ptr = i->p;
		ptr->ino = 0;
        ptr->ft = ptr->st[total_itr-1] + ptr->bt[total_itr -1];
        ptr->tat = ptr->ft - ptr->at[0];        

		for(j = 0; j < total_itr; j++)
			total_bt += ptr->bt[j];


		ptr->ino++;

		for(j = 0; j < n; j++)
			if(p_arr[j] == ptr->pid)
			{
				flag = 1;
				break;
			}
				
		if(flag == 0)
		{
			p_arr[k++] = ptr->pid;
			printf("\n%d\t%0.2f\t%0.2f", ptr->pid, ptr->tat - (total_bt + io_burst), ptr->tat);
			awt += ptr->tat - (total_bt + io_burst);
			atat += ptr->tat;
        
		}
		i = i->next;

    }

	printf("\nAverage WT : %f", awt/n);
	printf("\nAverage  TAT: %f\n", atat/n);	
}

void cal_b1_time()
{
	struct p_seq *sptr;
	struct process *ptr;
	float tat = 0, awt = 0, l_ft = 0;
	int total_processes = 0;
	printf("\nPID\tWT\tTAT");
	for(sptr = seq_front; sptr != NULL; sptr = sptr->next)
	{
		ptr = sptr->p;
		
			ptr->wt = ptr->st[0] - ptr->at[0];
			ptr->ft = ptr->st[0] + ptr->bt[0];		

		awt += ptr->wt;
		ptr->tat = ptr->ft - ptr->at[0];
		tat += ptr->ft - ptr->at[0];

		printf("\n%d\t%0.2f\t%0.2f", ptr->pid, ptr->wt, ptr->tat);
	} 
	

	printf("\n Average WT : %f", awt/n);
	printf("\n Average TAT : %f\n", tat/n);
}

void gannt_c()
{
	struct p_seq *ptr;
	int i = 0;
	float j;
	printf("\n\t\t***** Gantt Chart *****\n\n");
printf("-----------------------------------------------------------------------------------------------------------------");
	printf("\n");
	for(ptr = seq_front; ptr != NULL; ptr = ptr->next)
		ptr->p->ino = 0;

	for(ptr = seq_front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->p->bt[ptr->p->ino]; i++)
			printf(" ");
		printf("p%d", ptr->p->pid);
		for(i = 0; i < ptr->p->bt[ptr->p->ino]; i++)
			printf(" ");
		printf("|");

		if((ptr->next != NULL) && ptr->p->ft != ptr->next->p->st[ptr->next->p->ino])
		{
			
			for(j = 0.5; j <= (ptr->next->p->st[ptr->next->p->ino] - ptr->p->ft);j += 0.5)
				printf("*");				
		}
		ptr->p->ino++;
	}
printf("\n--------------------------------------------------------------------------------------------------------------\n");

}


void printGanttChart()
{
	struct p_seq *ptr;
	
	int i = 0;
	float j;
	printf("\n\t\t***** Gantt Chart *****\n\n\t");

	for(ptr = seq_front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->p->ft; i++)
			printf("--");
		printf("---");

		if((ptr->next != NULL) && ptr->p->ft != ptr->next->p->st[ptr->next->p->ino])
		{
			
			for(j = 0.5; j <= (ptr->next->p->st[ptr->next->p->ino] - ptr->p->ft);j += 0.5)
				printf("-");
			printf("---");
				
		}
	}
	printf("");
	printf("\n\t|");
	for(ptr = seq_front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->p->ft; i++)
			printf(" ");
		printf("p%d", ptr->p->pid);
		
		for(i = 0; i < ptr->p->ft; i++)
			printf(" ");

		printf("|");
		if(ptr->next != NULL && ptr->p->ft != ptr->next->p->st[ptr->next->p->ino])
		{
			for(j = 0.5; j <= (ptr->next->p->st[ptr->next->p->ino] - ptr->p->ft);j += 0.5)
				printf("**");
			printf("|");
				
		}

	}
	printf("\n\t");
	for(ptr = seq_front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->p->ft; i++)
			printf("--");
		printf("---");

		if(ptr->next != NULL && ptr->p->ft != ptr->next->p->st[ptr->next->p->ino])
		{
			for(j = 0.5; j <= (ptr->next->p->st[ptr->next->p->ino] - ptr->p->ft);j += 0.5)
				printf("-");
			printf("---");
				
		}
	}

	printf("\n\t0");

	for(ptr = seq_front; ptr != NULL; ptr = ptr->next)
	{
		for(i = 0; i < ptr->p->ft; i++)
			printf("  ");
		printf("%0.1f", ptr->p->ft);
		
		if(ptr->next != NULL && ptr->p->ft != ptr->next->p->st[ptr->next->p->ino])
		{
			for(j = 0.5; j <= (ptr->next->p->st[ptr->next->p->ino] - ptr->p->ft);j += 0.5)
				printf("  ");
			printf("%0.1f", ptr->next->p->st[ptr->next->p->ino]);
				
		}

	}

	printf("\n\n");

}


int main()
{
    int i;
    struct p_seq *itr;

	printf("how many iterations are there :");
	scanf("%d", &total_itr);
    printf("how many processes are there :");
    scanf("%d", &n);
    
	for (i = 0; i < n; i++)
          addToJobQueue(newProcess(i));
    system("clear");
	printf("\n\n\n");
    sjf_algo();

	print_seq();

	if(total_itr > 1)
	{
		calculate_time();
		gannt_c();
	}
	else
	{
		cal_b1_time();
		printGanttChart();
    }
	return 0;
}
