#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
typedef struct file
{
  char *name;
  int indx;
  int *indxb;
  struct file *next;
} file;
int N, j, i;
int *bv;
file *head, *cur, *new, *tail;
void printDir ();
char *newFile ();
char *deleteFile ();
int
main (void)
{
  int n = -1, flag, choice;
  printf ("Enter disk size:");
  flag = 0;
  while (n < 1)
    {
      if (flag)
	printf ("Renter the disk size:");
      scanf ("%d", &n);
      flag = 1;
    }
  N = n;
  bv = (int *) malloc (sizeof (N));
  for (i = 0; i < n; ++i)
    {
bv[i] = 1;		//1 for free
    }
  do
    {
printf
	("\n1)Show the bit vector\n2)Create new File\n3)Show directory\n4)Delete file\n5)Exit =>");
scanf ("%d", &choice);
switch (choice)
	{
case 1:
	  {
printf ("This is is bit vector \n");
for (i = 0; i < n; ++i)
	      {
printf ("%d ", bv[i]);
}             
printf ("\n");
}         
	  break;
case 2:
	  {
printf (newFile ());
}         
	  break;
case 3:
	  {
printDir ();
}         
	  break;
case 4:
	  {
printf (deleteFile (), "\n");
}         
	  break;
case 5:
	  exit (-1);
}
}   
  while (choice > 0 && choice < 5);

}

char *
newFile ()
{
  int flag = 0;
  char name1[128];
  int start, count = 0;
  printf ("Enter name of file:");
  scanf ("%s", name1);
  printf ("Enter the size:");
  scanf ("%d", &j);
  new = malloc (sizeof (file));
  if (!new)
    return "System Err";
  flag = 1;
  for (i = 0; i < N; ++i)
    {
      if (bv[i] == 1)
	++count;
      if (flag)
	start = i, flag = 0;
    }
  if (count < j)
    return "memory not available on disk";

  new->name = (char *) malloc (sizeof (strlen (name1)));
  new->indx = start;
  new->indxb = (int *) malloc (sizeof (int) * j);	//int of j number of times
  new->next = NULL;
}

char *
deleteFile ()
{
return "not implemented yet!!!";
}

void
printDir () 
{
cur = head;
j = 1;
if (!cur)
    return;
while (cur)
    {
printf ("%d) %s\n", j, cur->name);
++j;  
      cur = cur->next;
}   
  
    //printf("%d) %s\n",j,cur->name);
}

