#include<stdio.h>
#include<stdlib.h>

int **NEED,**ALLOCATION,**MAX,*WORK,*AVAILABLE,*FINISH,n,m;

void assign(int** Ar,int type)
{
	int i,j,count;
	printf("");
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{	
			if(type==1)
			{
			count=0;
				do
				{
				if(count == 1)
				printf("\n RE-Enter the value of Element as you may have entered the value less than 0 or IT is greater than Available Resource  ==> ");
				count=0;	
				printf("\n Enter the Element MAX value of P%d of Resource(%d) ==> ",i,j);
				scanf("%d",&(Ar[i][j]));
					if(!(Ar[i][j]>=0 && Ar[i][j]<=AVAILABLE[j]))
						count=1;
				}while(count==1);
			}
	
			if(type==2)
			{
				count=0;
				do
				{
				if(count == 1)
				printf("\n RE-Enter the value of Element as you may have entered the value less than 0 or IT is greater than Available Resource  ==> ");
				count=0;	
				printf("\n Enter the Element ALLOCATION value of P%d of  Resource(%d) ==> ",i,j);
				scanf("%d",&(Ar[i][j]));
					if(!(Ar[i][j]>=0 && Ar[i][j]<=MAX[i][j]))
						count=1;
				}while(count==1);
			}
			
		}
	}	
}


void print(int** Ar)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		printf("\n P%d |",i);
		for(j=0;j<m;++j)
		{
			printf(" %d  ",Ar[i][j]);
		}
	}	
}

void create_allocate()
{
	int i,j,count=0;
	do
	{
	if(count!=0)
	{
		printf("\n Re-Enter the values as you may have entered values of process or resources less than or is equal  to 0");
	}
	printf("\n Enter the number of process    ==> ");
	scanf("%d",&n);
	printf("\n Enter the number of Resources  ==> ");
	scanf("%d",&m);
	count =1;
	
	}while(n<=0 || m<=0);
	
	NEED =(int **)malloc(n  * sizeof(int *));
	for(i=0;i<n;++i)
		NEED[i]=(int *)malloc(m*sizeof(int));
	
	WORK = (int *)malloc(m * sizeof(int));

	AVAILABLE = (int *)malloc(m * sizeof(int));
	for(i=0;i<m;++i)
	{   count=1;
		do
		{
		if(count!=1)
		{
			printf("\n Re-Enter the values of Resource as it should be greater than 0");
		}
			printf("\n Enter the Total Available of Resource(%d) : ",i +1);
			scanf("%d",&AVAILABLE[i]);
			WORK[i]=AVAILABLE[i];
			if(AVAILABLE[i]<=0)
				count=0;
		}while(AVAILABLE[i]<=0);
	}		

	printf("\n Enter the Values of MAX : ");
	MAX =(int **)malloc(n  * sizeof(int *));
	for(i=0;i<n;++i)
		MAX[i]=(int *)malloc(m*sizeof(int));

	assign(MAX,1);
	printf("\n Enter the Values of ALLOCATION  : ");

	ALLOCATION =(int **)malloc(n  * sizeof(int *));
	for(i=0;i<n;++i)
		ALLOCATION[i]=(int *)malloc(m*sizeof(int));
	assign(ALLOCATION,2);
	printf("\n\n ALLOCATION MATRIX\n ");
	print(ALLOCATION);

	printf("\n\n MAX MATRIX\n ");
	print(MAX);
	// calculate Available,Work and Need matrix
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			WORK[j]=WORK[j]-ALLOCATION[i][j];
			NEED[i][j]=MAX[i][j]-ALLOCATION[i][j];
		}
	}
	
	printf("\n TOTAL AVAILABLE RESOURCE MATRIX :-->   | ");
	for(i=0;i<m;++i)
		printf("%d  | ",WORK[i]);

	printf("\n NEED MATRIX");
	print(NEED);

	FINISH =(int*)malloc(m*sizeof(int));
	for(i=0;i<m;++i)	
		FINISH[i]=0;
}

	void safe()
	{
		int *SAFE_STATE = (int*)malloc(m*sizeof(int));
		int t,i,j,k,count=0,flag;
		for(k=0;k<n;++k)
		{
			for(i=0;i<n;++i)
			{
				if(FINISH[i]==0)
				{
					flag=0;
					for(j=0;j<m;++j)
					{
						if(NEED[i][j]>WORK[j])
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						SAFE_STATE[count++]=i;
						for(t=0;t<m;++t)
							WORK[t]+=ALLOCATION[i][t];
						FINISH[i]=1;
					}
				}
			}
		}

		flag=1;
		for(i=0;i<n;++i)
		{
			if(FINISH[i]==0)
			{
				flag=0;
				printf("\n THE FOLLOWING STATE IS NOT IN SAFE STATE");
				break;
			}
		}
		
		if(flag==1)
		{
			printf("\n SYSTEM IS IN SAFE STATE and \n FOLLOWING IS THE SAFE SEQUENCE :--> ");
			for(i=0;i<n-1;++i)
				printf(" P%d=> ",SAFE_STATE[i]);
			printf(" P%d ",SAFE_STATE[n-1]);
		}	
	}

	void main()
	{
		create_allocate();
		safe();
	}
