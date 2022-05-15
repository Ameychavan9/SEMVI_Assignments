#include<stdio.h>
#include<stdlib.h>

int *str,*frame,p,n,i;

int search(int key)
{
	for(i=0;i<n;i++)
	if(frame[i]==key)	
	return i;
	return -1;
}

void shift(int z)
{ 
	int r=frame[z];
	for(i=z;i<n;i++)frame[i]=frame[i+1];frame[i]=r;
}

void display()
{
	for(i=0;i<n;i++)
	printf("%d",frame[i]);
	printf("\n");
}
 
void LRU()
{
	int k=-1,c=0,i,z;
	printf("\n\nPage Replacement table\n");
	while(c<n)
	{
		k++;
		z=search(str[k]);
		if(z!=-1){shift(z);display();continue;}
		else
		{
			frame[0]=str[k];
			shift(0);
			display();c++;
		}
	}
	while(k<p)
	{
		k++;
		printf("\nk: %d\n ",str[k]);
		z=search(str[k]);
		if(z!=-1){
			shift(z);
			continue;}
		else 		
		{
			frame[0]=str[k];
			shift(0);
			display();c++;	
		}
	}
	printf("\n\n NO of Page Faults: %d\n",c);
}
void main()
{
		int i;
		printf("\nEnter no of pages: ");
		scanf("%d",&p);
		str=(int*)malloc(p*sizeof(int));	
		printf("\n Enter The Reference String : ");
		for(i=0;i<p;i++)scanf("%d",&str[i]) ;
		printf("\n Enter  No of Frames :");
		scanf("%d",&n);
	
		frame=(int*)malloc(n*sizeof(int));
		LRU();
}
	
