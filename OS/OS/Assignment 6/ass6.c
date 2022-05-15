#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dirent{
	char fname[10];
	int start,len;
	struct dirent *next;
}*head=NULL,*curr,*new,*tmp;
int *memory;
void Display()
{
	struct dirent *d=head;
	while(d!=NULL)
	{
		printf("\n\nFile Name: %s",d->fname);
		printf("\nStart Block: %d",d->start);
		printf("\nLength: %d",d->len);
		d=d->next;
	}
}
void main()
{
	int n,i,j,c,no,start;
	char name[10];
	printf("\nEnter No. of Blocks: ");
	scanf("%d",&n);
	memory=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)memory[i]=0;
	while(1)
	{
		printf("\n\n1.Show Memory Array");
		printf("\n2.Create New File");
		printf("\n3.Show Directory");
		printf("\n4.Delete File");
		printf("\n5.Exit");
		printf("\n\nEnter Your Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("\nStatus of Memory Blocks: ");for(i=0;i<n;i++)printf("%d ",memory[i]);break;

			case 2:printf("\nEnter File Name: ");
			       scanf("%s",name);
		               printf("\nEnter No. of Blocks to Allocate: ");
			       scanf("%d",&no);
			       while(no>n)
			       {
				       printf("\nBlocks Out Of Bound! Enter Valid Input: \n");
			       	       scanf("%d",&no);
			       }
			       int done;
			       for(i=0;i<n;i++)
			       {
				       done=0;
				       if(memory[i]==0)
				       {
					       int flag=0;
					       for(j=i;j<i+no;j++)
					       {
						       if(memory[j]==1){i=j;flag=1;break;}
					       }
					       if(flag==0&&j!=i)
					       {
						       start=i;done=1;break;
					       }
				       }
				       if(done==1)break;
			       }
			       if(done==0)printf("\nSpace Couldnt Be Allocated");
			       else{
				       printf("\nstart: %d",start);
				       if(head==NULL)
				       {
				       new=(struct dirent *)malloc(sizeof(struct dirent));
				       strcpy(new->fname,name);
				       new->start=start;
				       new->len=no;
				       new->next=NULL;
				       head=new;
				       }
				       else
				       {
				       tmp=head;
				       while(tmp->next!=NULL)tmp=tmp->next;
				       new=(struct dirent *)malloc(sizeof(struct dirent));
				       strcpy(new->fname,name);
				       new->start=start;
				       new->len=no;
				       new->next=NULL;
				       tmp->next=new;
				       }
				       for(i=start;i<start+no;i++)memory[i]=1;
			       }
			       break;


			case 3:Display();break;

			case 4:printf("\nEnter File Name: ");
			       scanf("%s",name);
			       tmp=head;
			       curr=head;
			       c=0;
			       while(tmp!=NULL)
			       {
				       if(!strcmp(tmp->fname,name))
				       {
					       for(i=tmp->start;i<tmp->start+tmp->len;i++)
					       {
						       memory[i]=0;
					       }
					       if(curr==head)
					       {
						       if(curr->next==NULL)head=NULL;
						       else head=curr->next;
						     
					       }
					       else curr->next=curr->next->next;
					       printf("\nFile Deleted Successfully\n");
					       c=1;break;    
				       }
				       else
				       {
					       curr=tmp;
					       tmp=tmp->next;
				       }
			       }
			       if(c!=1)printf("\nFile Not Found\n");
			       break;

			case 5:exit(0);break;
		}
	}
}
