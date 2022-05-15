#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **frames, p, n, next = 0, prs[100], page_faults = 0, counter = 1, default_max = 10000;

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

int max_count_index()
{
    int i = 0, j = 0, max_count = -1, index = -1,last;
    for (i = 0; i < n; i++)
    {
        if (frames[i][1] > max_count)
        {
            max_count = frames[i][1];
            index = i;
        }
        else if(frames[i][1] == max_count && frames[i][1] != default_max)
        {
            last = frames[0][2];
            for(j = 0; j < n; j++)
            {
                if(frames[j][2] < last)
                {
                    index = j;
                    last = frames[j][2];
                }
            }
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

void mfu()
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
                    frames[j][1] += 1;
                    frames[j][2] = counter++;
                    break;
                }
            }
        }
        else
        {
            index = max_count_index();
            frames[index][0] = prs[i];
            frames[index][1] = 0;
            frames[index][2] = counter++;
            page_faults++;
        }
        printFrames();

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
        frames[i] = (int *)malloc(sizeof(int) * 3);
        frames[i][0] = -1;
        frames[i][1] = default_max;
        frames[i][2] = -1;
    }

    printf("Enter Page referance string:\n(separated by space):");
    i = 0;
    do
    {
        scanf("%d", &prs[i++]);
    } while (getchar() != '\n' && i < p);

    mfu();
    printf("\nTotal page faults: %d\n", page_faults);

    return 0;
}
