#include <stdio.h>
#include "fcfs.h"

int main()
{
	int i, n;
	float at, bt;
	
	printf("Enter no of processes : ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("\nEnter details for process %d ", i);
		printf("\nArrival time : ");
		scanf("%f", &at);
		printf("Brust time : ");
		scanf("%f", &bt);
		addNewNode(i, at, bt);	
	}
	system("clear");
	calculateTime();
	printQueue();
	printGanttChart();
		
}
