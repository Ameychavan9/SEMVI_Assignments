#include<stdio.h>
#include<stdlib.h>

int n,**frame,*PageRefStr,P,pagefault=0;

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
    while(n<0)
    {
        printf("\n Re-Enter the number of frames as it should be greater than 0 : ");
        scanf("%d",&n);
    }
    frame=(int **)malloc(n*sizeof(int*));
    for(i=0;i<n;++i)
        frame[i]=(int *)malloc(3*sizeof(int));  
    printf("\n Ref String \n Page no");
    for(i=0;i<n;++i)
        {
            frame[i][0]=-1;
            frame[i][1]=0;
            frame[i][2]=0;
            printf("\t\t Frame %d",i+1);
        }
}

void mfu()
{
    int i,counter,j,ind,max,f=0;  // f --> frames no.
    for(i=0;i<P;++i)
    {   counter=0;
        for(j=0;j<n;++j )
        {
            if(frame[j][0]==PageRefStr[i])
            {
                counter++;
                pagefault--;
                frame[j][1]+=1;
                frame[j][2]=i+1;
            }
        }
        pagefault++;
        if((pagefault<=n) && counter==0)
        {
            frame[f][0]=PageRefStr[i];
            frame[f][1]=1; 
            frame[f][2]=i+1;
            f++;
        }

        //-----------------------------------------------
        else if(counter==0)
        {
            max=-1;
            for(j=0;j<n;++j)
            {
                // check for min frame frequency and counter comparision    
                if(max<=frame[j][1])
                {
                    if(max<frame[j][1])
                    {
                        max=frame[j][1];
                        ind=j;
                    }           
                    else
                        if(frame[ind][2]>frame[j][2])
                            ind=j;
                }
            }
            frame[ind][0]=PageRefStr[i];
            frame[ind][1]=1;
            frame[ind][2]=i+1;
        }
        printf("\n    %d\t\t",PageRefStr[i]);
        for(j=0;j<n;++j)
        {
            if(frame[j][0]!=-1)
                printf("\t%d | %d | %d \t",frame[j][0],frame[j][1],frame[j][2]);
            else
                printf(" \t- \t\t");
        }
        if(counter == 0)
            printf("\t ->  Pagefault");
        else    
            printf("\t ->  Hit");
    }
    printf("\n Total number of Page Faults: \t%d ",pagefault);
}

void main()
{
    create();
    mfu();
}