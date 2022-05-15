#include<stdio.h>
#include<stdlib.h>
int *str,*frame,p,n,i,*Frame;

int search(int key){for(i=0;i<n;i++)if(frame[i]==key)return 1;return 0;}

int shift(){int r=frame[0];for(i=0;i<n;i++)frame[i]=frame[i+1];frame[i]=0;return r;}

void display(){for(i=0;i<n;i++)printf("%d ",Frame[i]);printf("\n");}

void fifo()
{
	int rear=0,front=0,k=-1,c=0,i,z;
	printf("\n\nPage Replacement Table\n");
	for(rear=0;rear<n && k<p;rear++)
	{
		k++;
		if(search(str[k])){display();rear--;continue;}
		else {frame[rear]=str[k];Frame[rear]=str[k];display();c++;}
	}
	rear=n-1;
	while(k<p-1)
	{
		k++;
		if(search(str[k])){display();continue;}
		else
		{
			z=shift();
			for(i=0;Frame[i]!=z;i++);
			Frame[i]=str[k];
			frame[rear]=str[k];
			display();c++;
		}
	}
	printf("\n\nNo. of Page Faults: %d\n",c);
}

void main()
{
	int i;
	printf("\nEnter No. of Pages: ");
	scanf("%d",&p);
	str=(int*)malloc(p*sizeof(int));
	printf("\nEnter Reference String: ");
	for(i=0;i<p;i++)scanf("%d",&str[i]);
	printf("\nEnter No. of Frames: ");
	scanf("%d",&n);
	frame=(int*)malloc(n*sizeof(int));
	Frame=(int*)malloc(n*sizeof(int));
	fifo();
}
