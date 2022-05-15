#include<stdio.h>
#include<stdlib.h>

int **NEED,**ALLOCATION,**MAX,*WORK,*AVAILABLE,*FINISH,n,m,*REQUEST,*TOTAL;
char ch ='A';
void cal();

void assign(int** Ar,int type)
{
    int i,j,count;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if(type==1)
            {
                printf("\n Enter the MAX value of P%d of Resource(%c): ",i,(char)(ch+j));
                scanf("%d",&Ar[i][j]);
                while(!(Ar[i][j]>=0 && Ar[i][j]<=AVAILABLE[j]))
                {
                    printf("\n Re-Enter the value as you may have enteed the value less than 0 or greater than available resource :  ");
                    printf("\n Enter the MAX value of P%d of Resource(%c): ",i,(char)(ch+j));
                    scanf("%d",&Ar[i][j]);
                }
            }
            if(type==2)
            {
                printf("\n Enter the ALLOCATION value of P%d of Resource(%c): ",i,(char)(ch+j));
                scanf("%d",&Ar[i][j]);
                while(!(Ar[i][j]>=0 && Ar[i][j]<=MAX[i][j]))
                {
                    printf("\n Re-Enter the value as you may have enteed the value less than 0 or greater than MAX resource :  ");                        
                    printf("\n Enter the ALLOCATION value of P%d of Resource(%c): ",i,(char)(ch+j));
                    scanf("%d",&Ar[i][j]);                        
                }   
            }
        }
    } 
}

void print(int** Ar)
{
    int i,j;
    printf("\n\n      |");
    for(j=0;j<m;++j)
        printf("   %c  |",(char)(ch+j));
    printf("\n");
    for(j=0;j<m+1;++j)
        printf("-------");
    for(i=0;i<n;++i)
    {
        printf("\n|  P%d | ",i);
        for(j=0;j<m;++j)
        {
            printf(" %d   | ",Ar[i][j]);
        }
    }
    printf("\n");
    for(j=0;j<m+1;++j)
        printf("-------"); 
}

int safe()
{
    int *SAFE_STATE = (int*)malloc(n*sizeof(int));
    int t,i,j,k,count=0,flag;
    for (k = 0; k < n; k++) 
	{
	for (i = 0; i < n; i++) 
        {
	if (FINISH[i] == 0) 
            {
		flag = 0;
		for (j = 0; j < m; j++) 
                {
		if (NEED[i][j] > WORK[j])
                    {
			flag = 1;
			break;
	   	    }
		}

		if (flag == 0) 
                {
		SAFE_STATE[count++] = i;
		for (t = 0; t < m; t++)
			WORK[t] += ALLOCATION[i][t];
			FINISH[i] = 1;
		}
	   }
	 }
       }

	flag = 1;
	for( i=0;i<n;i++)
	{
	    if(FINISH[i]==0)
	    {
		    flag=0;
		    printf("\n\nThe following System is not safe state" );
		    return 0;
	    }
	}
	if(flag==1)
	{
	printf("\n\n System is in the Safe State and \n Following is the SAFE Sequence :-->   ");
	for (i = 0; i < n-1 ; i++)
		printf(" P%d ->", SAFE_STATE[i]);
	printf(" P%d", SAFE_STATE[n - 1]);
	}
    return 1;
}

void create_allocate()
{
    int i,j,count=0;
    printf("\n Enter the number of Process   : ");
    scanf("%d",&n);
    while(n<=0)
    {
        printf("\n Re-Enter the number of process as it cannot be less than Zero : ");
        scanf("%d",&n);
    }
    printf("\n Enter the number of Resources : ");
    scanf("%d",&m);
    while(n<=0)
    {
        printf("\n Re-Enter the number of Resources as it cannot be less than Zero : ");
        scanf("%d",&m);
    }
    
    NEED = (int **)malloc(n * sizeof(int*));
    for(i=0;i<n;++i)
        NEED[i]=(int*)malloc(m*sizeof(int));

    WORK = (int*)malloc(m*sizeof(int));
    AVAILABLE = (int*)malloc(m*sizeof(int));
    TOTAL = (int*)malloc(m*sizeof(int));
        for(i=0;i<m;++i)
        {
            printf("\n Enter the total number of Available Resoure of type %c : ",(char)(ch+i));
            scanf("%d",&AVAILABLE[i]);
            while(AVAILABLE[i]<=0)
            {
                printf("\n Re-Enter the value of Resources as it should be greater than 0  : ");
                printf("\n Enter the total number of Available Resoure of type %c : ",(char)(ch+i));
                scanf("%d",&AVAILABLE[i]);
            }   
            WORK[i]=AVAILABLE[i];
            TOTAL[i]=AVAILABLE[i];
        }

    printf("\n <== Enter the values for MAX ==> ");
    MAX = (int **)malloc(n * sizeof(int*));
    for(i=0;i<n;++i)
        MAX[i]=(int*)malloc(m*sizeof(int));

    assign(MAX,1);

    printf("\n <== Enter the values for allocation ==> ");
    ALLOCATION = (int **)malloc(n * sizeof(int*));
    for(i=0;i<n;++i)
        ALLOCATION[i]=(int*)malloc(m*sizeof(int));
    assign(ALLOCATION,2);

    printf("\n\t ALLOCATION MATRIX \n");
    print(ALLOCATION);
    
    printf("\n\n\t MAX MATRIX \n");
    print(MAX);   
    cal();
}

void cal()
{
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
        {
            AVAILABLE[j]-=ALLOCATION[i][j];            
            WORK[j]=WORK[j]-ALLOCATION[i][j];
            NEED[i][j]=MAX[i][j]-ALLOCATION[i][j];
        }

    printf("\n\n\t AVAILABLE MATRIX\n\n      |");
    for(j=0;j<m;++j)
        printf("   %c  |",(char)(ch+j));
    printf("\n      |");
        for(j=0;j<m;++j)
           printf(" %d | ",AVAILABLE[j]);
        
    printf("\n\n\t NEED MATRIX ");
    print(NEED);
    FINISH = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;++i)
        FINISH[i]=0;
}

int main()
{
    int p,choice,n1,j,p1=2;
    char ch1;
    create_allocate();
    p=safe();
   if(p==1)
    {
        do
        {
            REQUEST= (int*)malloc(m * sizeof(int));
            for(j=0;j<m;++j)
            {
                //AVAILABLE[j]=TOTAL[j];
                WORK[j]=TOTAL[j];
            }
            printf("\n\n\t\t ALLOCATION MATRIX");
            print(ALLOCATION);
            printf("\n\n\t\t MAX MATRIX");
            print(MAX);
            printf("\n\n\t\t NEED MATRIX");
            print(NEED);
            printf("\n For which process you want to request additional resources : ");
            printf("\n Enter the Process number :--> ");
            scanf("%d",&choice);

	// ------------------------------------------------
 	    printf("\n\n\t AVAILABLE MATRIX\n\n      |");
	    for(j=0;j<m;++j)
	        printf("   %c  |",(char)(ch+j));
	    printf("\n      |");
            for(j=0;j<m;++j)
          	 printf(" %d | ",AVAILABLE[j]);

	// ----------------------------------------------	
            if(choice>=0 && choice < n)
            {
                for(j=0;j<m;++j)
                {
                    printf("\n Enter the REQUEST for P%d Resource(%c): ",choice,(char)(ch+j));                       
                    scanf("%d",&REQUEST[j]);
                    if(!(REQUEST[j]<=AVAILABLE[j] && REQUEST[j]>=0))
                    {
                        printf("\n Request cannot be granted as this many resources are not available currently or you have entered value less tha 0 ");
                        p1=0;
			break;        
                    }
                    else
                    {
                        if(!(ALLOCATION[choice][j]<=MAX[choice][j]))
                        {
                            printf("\n ALLOCATION EXCEEDS MAX \n Re-Enter The request for all resorces");
			    j=0;
                            p1=0;
				break;
                        }
                        ALLOCATION[choice][j]+=REQUEST[j];
                    }
                }    
                if(p1==2)
                {
                    for(j=0;j<m;++j)
			{
			WORK[j]=TOTAL[j]; //---- ADDED
			AVAILABLE[j]=TOTAL[j];
			}
                    cal();
		    p=safe();
			if(p==1)
                  	  printf("\n Request is granted immediately ");
                }
                else
                {
                    printf("\n Request cannot be granted immediately.");
                  /*  for(j=0;j<m;++j)
                    {
                        AVAILABLE[j]+=REQUEST[j];            
                        WORK[j]=WORK[j]+REQUEST[j];
                        ALLOCATION[choice][j]-=REQUEST[j];
                        NEED[choice][j]+=REQUEST[j];
                    }*/                                               
                }
            }
            else
                printf("\n Invalid process ID");
            free(REQUEST);        
            printf("\n Do you want to continue and want to add request for another process(y/n) : ");
            scanf("%d",&n1);
            scanf("%c",&ch1);              
        }while(ch1 == 'y' || ch1 == 'Y');
    }
}
