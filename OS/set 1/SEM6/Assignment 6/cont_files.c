#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct direct_entry
{
    char filename[10];
    int start_block, length;
    struct direct_entry *next; 
}*head = NULL, *rear = NULL, *new = NULL, *cur = NULL;

int *bit_vector, n;

struct direct_entry newFile(char fn[10], int sb, int length);
void addFile(struct direct_entry *file_);
void createNewFile();
void showBitVector();


int main()
{
    int i;
    printf("Enter the size of bit vector :");
    scanf("%d", &n);
    bit_vector = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
        bit_vector[i] = 1;
    
    showBitVector();
    
}

struct direct_entry newFile(char fn[10], int sb, int length)
{
    struct direct_entry *n = (struct direct_entry *)malloc(sizeof(struct direct_entry));
    strcpy(n->filename, fn);
    n->start_block = sb;
    n->length = length;
    n->next = NULL;
}

void addFile(struct direct_entry *file_)
{
    if(head == NULL)
    {
        head = file_;
        rear = head;
    }
    else
    {
        rear->next = file_;
        rear = rear->next;
    }
}

void createNewFile()
{
    char filename[10];
    printf("");
}

void showBitVector()
{
    int i;
    printf("\nBit Vector :");
    for(i = 0; i < n; i++)
        printf("[%d] ", bit_vector[i]);
}