#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *bit_verctor, n;
FILE *fp = NULL;

struct block
{
    int block_num;
    struct block *next;
} *b_front = NULL, *b_rear =NULL;

struct dir_entry
{
    char filename[10];
    int start_block, end_block, length;
    struct dir_entry *next;
} *front = NULL, *rear = NULL;

void createBitVector();
void showBitVector();
int freeBlockCount();
void addNewFile();
void createBlocks(int);
void addToDirectory(struct dir_entry *ptr);
void showDirectory();


int main()
{
    int choice;
    struct dir_entry *ptr;
    char fn[20];
    createBitVector();

    do
    {

        printf("\n\tEnter your choice.\n");
        printf("\t1.Show Bit Vector.\n\t2.Create new file.\n\t3.Show Directory.\n\t4.Delete file.\n\t5.Exit.\n\t>>>");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showBitVector();
            break;

        case 2:
            addNewFile();
            break;

        case 3:
            showDirectory();
            break;
        case 4:
            //delete_file();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid input.\n");
            break;
        }

    } while (choice != 5);

    return 0;
}

void createBitVector()
{
    int i;
    printf("Enter size of bit vector(n):");
    scanf("%d", &n);

    bit_verctor = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        bit_verctor[i] = 1;
}

void showBitVector()
{
    int i, free_count = 0;
    printf("\nBit vector: ");
    for (i = 0; i < n; i++)
        printf("[%d] ", bit_verctor[i]);

    printf("\nTotal no of blocks : %d", n);
    for (i = 0; i < n; i++)
        if (bit_verctor[i] == 1)
            free_count++;
    printf("\nTotal no of free blocks : %d\n", free_count);
}

int freeBlockCount()
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (bit_verctor[i] == 1)
            count++;
    }

    return count;
}

void addNewFile()
{
    char fn[10], temp[50];
    int sb, len;
    struct dir_entry *n = (struct dir_entry *)malloc(sizeof(struct dir_entry)), *ptr;
    printf("\nEnter file name:");
    scanf("%s", fn);

    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printf("%s", ptr->filename);
        if (strcmp(ptr->filename, fn) == 0)
        {
            printf("File with name %s already exists.\n", fn);
            free(n);
            return;
        }
    }

    strcpy(n->filename, fn);

    printf("\nEnter length:");
    scanf("%d", &len);
    n->length = len;

    if(len < freeBlockCount())
    {
        sprintf(temp, "./files/%s", fn);
        fp = fopen(temp, "w");

        if(b_front == NULL)
            n->start_block = 0;
        else
            n->start_block = b_rear->block_num + 1;
        n->end_block = n->start_block + len;
        addToDirectory(n);
        createBlocks(len);
    }
    else
    {
        printf("\nCan't allocate memory to file. Free blocks not available.\n");
        free(n);
    }
}

void addToDirectory(struct dir_entry *ptr)
{
    if (front == NULL)
    {
        front = ptr;
        rear = front;
    }
    else
    {
        rear->next = ptr;
        rear = rear->next;
    }
}

void createBlocks(int len)
{
    struct block *b;
    int i;
    for(i = 0; i < len; i++)
    { 
        b = (struct block *)malloc(sizeof(struct block));
        if(b_front == NULL)
        {
            b->block_num = 0;
            b_front = b;
            b_rear = b_front;
        }
        {
            b->block_num = b_rear->block_num + 1;
            b_rear->next = b;
            b_rear = b_rear->next;
        }
        bit_verctor[b->block_num] = 0;
    }
}

void showDirectory()
{
    struct dir_entry *ptr;
    if (front == NULL)
        printf("\nDirectory is empty.\n");
    else
    {
        printf("\nDirectory\nFile    \tStart Block\tlength\n");
        for (ptr = front; ptr != NULL; ptr = ptr->next)
            printf("%s\t\t%d\t%d\n", ptr->filename, ptr->start_block, ptr->length);
        printf("\n");
    }
}