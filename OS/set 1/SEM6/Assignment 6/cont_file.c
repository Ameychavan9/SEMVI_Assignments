#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *bit_verctor, n;
FILE *fp = NULL;

struct dir_entry
{
    char filename[10];
    int start_block, length;
    struct dir_entry *next;
} *front = NULL, *rear = NULL;

void createBitVector();
void showBitVector();
void showDirectory();
void addToDirectory(struct dir_entry *ptr);
void createNewFile();
int check_empty_blocks(int len);
void allocate_blocks(int sb, int len);
void delete_file();

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
            createNewFile();
            break;

        case 3:
            showDirectory();
            break;
        case 4:
            delete_file();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid input.\n");
            break;
        }

    } while (choice != 5);

    for(ptr = front; ptr != NULL; ptr = ptr->next)
    {
        sprintf(fn, "./files/%s", ptr->filename);
        remove(fn);
    }
    
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
    for(i = 0; i < n; i++)
        if(bit_verctor[i] == 1)
            free_count++;
    printf("\nTotal no of free blocks : %d\n",free_count);
}

void createNewFile()
{
    char fn[10], temp[50];
    int sb, len;
    struct dir_entry *n = (struct dir_entry *)malloc(sizeof(struct dir_entry)), *ptr;
    printf("\nEnter file name:");
    scanf("%s", fn);

    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {printf("%s", ptr->filename);
        if (strcmp(ptr->filename, fn) == 0)
        {
            printf("File with name %s already exists.\n", fn);
            return;
        }
    }

    strcpy(n->filename, fn);



    printf("\nEnter length:");
    scanf("%d", &len);
    n->length = len;
    addToDirectory(n);

    if (check_empty_blocks(len) != -1)
    {
        n->start_block = check_empty_blocks(len);
        allocate_blocks(check_empty_blocks(len), len);

        sprintf(temp, "./files/%s", fn);
        fp = fopen(temp, "w");
    }
    else
        printf("\nCan't allocate memory to file. Free blocks not available.\n");
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

void allocate_blocks(int sb, int len)
{
    int i = 0;
    for (i = sb; i < sb + len; i++)
        bit_verctor[i] = 0;
}

// fucntion check if we have free blocks available (provided lenght)
// returns -1 if no free blocks available
// else return start
int check_empty_blocks(int len)
{
    int i, empty_count = 0, start = 0;
    for (i = 0; i < n; i++)
    {
        if (bit_verctor[i] == 1)
        {
            empty_count++;
            if (empty_count == len)
                return i - (len - 1);
        }
        else
            empty_count = 0;
    }
    return -1;
}

void showDirectory()
{
    struct dir_entry *ptr;
    if(front == NULL)
        printf("\nDirectory is empty.\n");
    else
    {
        printf("\nDirectory\nFile    \tStart Block\tlength\n");
        for(ptr = front; ptr != NULL; ptr = ptr->next)
            printf("%s\t\t%d\t\t%d\n", ptr->filename, ptr->start_block, ptr->length);
        printf("\n");
    }
}

void delete_file()
{
    char fn[10], temp[50];
    struct dir_entry *ptr, *parent = NULL;
    int j;
    printf("Enter file name to delete :");
    scanf("%s", fn);

    for(ptr = front; ptr != NULL; ptr = ptr->next)
    {
        if(strcmp(ptr->filename, fn) == 0)
        {
            sprintf(temp, "./files/%s", fn);
            for(j = ptr->start_block; j < ptr->start_block + ptr->length; j++)
                bit_verctor[j] = 1;
            remove(temp);

            if(parent == NULL)
                front = front->next;
            else
                parent->next= ptr->next;
            return;
        }
        parent = ptr;
    }

    printf("\nfile does not exists.\n");
}