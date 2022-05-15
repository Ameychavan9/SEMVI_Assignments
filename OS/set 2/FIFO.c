#include<stdio.h>
#include<stdlib.h>

int n,*frame,*PageRefStr,P,pagefault=0;

void create()
{
    int i;
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
    frame=(int *)malloc(n*sizeof(int));
    while(n<0)
    {
        printf("\n Re-Enter the number of frames as it should be greater than 0 : ");
        scanf("%d",&n);
    }   
}

void page()
{
    int i,counter,j;
    printf("Incoming");
    for(i=0;i<n;++i)
        {
            frame[i]=-1;
            printf("\t\t Frame %d",i+1);
        }
    for(i=0;i<P;++i)
    {   counter=0;
        for(j=0;j<n;++j )
        {
            if(frame[j]==PageRefStr[i])
            {
                counter++;
                pagefault--;
            }
        }
        pagefault++;
        if((pagefault<=n) && counter==0)
            frame[i]=PageRefStr[i];
        else if(counter==0)
            frame[(pagefault-1)%n]=PageRefStr[i];

        printf("\n    %d\t\t",PageRefStr[i]);
        for(j=0;j<n;++j)
        {
            if(frame[j]!=-1)
                printf("\t%d\t\t",frame[j]);
            else
                printf(" \t- \t\t");
        }
    }

    printf("\n Total number of Page Faults: \t%d ",pagefault);
}

void main()
{
    create();
    page();
}