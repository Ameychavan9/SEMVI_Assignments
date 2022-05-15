#include<stdio.h>
#include<stdlib.h>

int n,**frame,*PageRefStr,P,pagefault=0;

void create()
{
    int i,j;
    printf("\n Enter number of pages : ");
    scanf("%d",&P);
    while(P<0)
    {
        printf("\n Re-Enter the number of pages as it should be greater than 0 : ");
        scanf("%d",&P);
    }
    PageRefStr=(int *)malloc(P*sizeof(int));
    printf("\n Enter the page reference string ==> ");
    for(i=0;i<P;++i)
        scanf("%d",&PageRefStr[i]);
    printf("\n Enter number of frames : ");
    scanf("%d",&n);
    while(n<0)
    {
        printf("\n Re-Enter the number of frames as it should be greater than 0 : ");
        scanf("%d",&n);
    }   
    frame=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;++i)
		frame[i]=(int*)malloc(2*sizeof(int));

    printf("\n Ref String \n Page no");
    for(i=0;i<n;++i)
        {
            frame[i][0]=-1;
	    frame[i][1]=0;
            printf("\t\t Frame %d",i+1);
        }
}


void lru()
{
    int i,counter,j,min,ind,f=0;
    for(i=0;i<P;++i)
    {   counter=0;
        for(j=0;j<n;++j )
        {
            if(frame[j][0]==PageRefStr[i])
            {
		frame[j][1]=i+1;
                counter++;
                pagefault--;
            }
        }
        pagefault++;
        if((pagefault<=n) && counter==0)
	{
		frame[f][0]=PageRefStr[i];
		frame[f][1]=i+1;
		f++;
	}
        else if(counter==0)
    	{
	        min=P+1;
		for(j=0;j<n;++j)	
		{
			if(min>frame[j][1])
			{
				min=frame[j][1];
				ind=j;
			}
		}
		frame[ind][0]=PageRefStr[i];
		frame[ind][1]=i+1;
	}
        printf("\n    %d\t\t",PageRefStr[i]);
        for(j=0;j<n;++j)
        {
            if(frame[j][0]!=-1)
                printf("\t%d | %d\t\t",frame[j][0],frame[j][1]);
            else
                printf(" \t- \t\t");
        }
	if(counter==0)
		printf("\t -> PAGEFAULT");
	else
		printf("\t -> HIT");
    }

    printf("\n Total number of Page Faults: \t%d ",pagefault);
}

void main()
{
    create();
    lru();
}
