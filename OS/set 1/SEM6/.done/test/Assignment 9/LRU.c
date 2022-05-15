#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **frames, p, n, next = 0, prs[100], page_faults = 0, counter = 1;

int is_present(int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (frames[i][0] == key)
            return 1;
    }
    return 0;
}

int min_count_index()
{
    int i = 0, min_count = 100000, index = -1;
    for (i = 0; i < n; i++)
    {
        if (frames[i][1] < min_count)
        {
            min_count = frames[i][1];
            index = i;
        }
    }
    return index;
}

void printFrames()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%2d ", frames[i][0]);
    printf("\n");
}

void lru()
{
    int i, j, index = 0;
    for (i = 0; i < p; i++)
    {
        if (is_present(prs[i]))
        {
            for (j = 0; j < n; j++)
            {
                if (frames[j][0] == prs[i])
                {
                    frames[j][1] = counter;
                    break;
                }
            }
        }
        else
        {
            index = min_count_index();
            frames[index][0] = prs[i];
            frames[index][1] = counter;
            page_faults++;
        }
        printFrames();
        counter++;
    }
}

int main()
{
    int i = 0;
    printf("Enter number of pages:");
    scanf("%d", &p);

    printf("Enter number of frames:");
    scanf("%d", &n);

    frames = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        frames[i] = (int *)malloc(sizeof(int) * 2);
        frames[i][0] = -1;
        frames[i][1] = -1;
    }

    printf("Enter Page referance string:\n(separated by space):");
    i = 0;
    do
    {
        scanf("%d", &prs[i++]);
    } while (getchar() != '\n' && i < p);

    lru();

    printf("\nTotal page faults :%d\n", page_faults);
    return 0;
}
