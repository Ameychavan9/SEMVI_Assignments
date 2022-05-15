#include <stdio.h>
#include <stdlib.h>

int **REQUEST, *WORK, *AVAILABLE, **ALLOCATION, *safe_seq, *temp;
int n, m, is_safe = 1;


void init_matrices();
void acceptAllocation();
void acceptRequest();
void acceptAvailable();
void safety_algo();
int cmp_tuple(int *a, int *b);
void copy_tuple(int *a, int *b);
void printMatrix(int **mat);



int main()
{

    int i, j;

    do
    {    
        printf("\nEnter number of processes (n) :");
        scanf("%d", &n);

        if(n <= 0)
            printf("Please enter number greater than 0.\n");
    } while (n <= 0);
    
    do
    {
        printf("\nEnter number of type of resource types (m) :");
        scanf("%d", &m);

        if(m <= 0)
            printf("Please enter number greater than 0.\n");
    } while (m <= 0);


    init_matrices();
    acceptAvailable();
    acceptAllocation();
    acceptRequest();

    printf("\nALLOCATION:\n");
    printMatrix(ALLOCATION);
    printf("\nREQUEST\n");
    printMatrix(REQUEST);

    safety_algo();


    if(is_safe == 1)
    {
        printf("\nNo deadlock found.\nSafe sequence :");
        for(i = 0; i < n; i++)
            printf("%d ", safe_seq[i]);
        printf("\n");
    }
    else{
        printf("\nSystem is not safe.\n");
    }

    return 0;
}

//  function to declare matrices.
void init_matrices()
{
    int i;
    AVAILABLE = (int *)malloc(sizeof(int) * m);
    temp = (int *)malloc(sizeof(int) * m);

    REQUEST = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++)
        REQUEST[i] = (int *)malloc(sizeof(int) * m);

    ALLOCATION = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++)
        ALLOCATION[i] = (int *)malloc(sizeof(int) * m);
}

// function to max allocation
void acceptAllocation()
{
    int allocation = 0, i, j;
    printf("Enter ALLOCATION matrix.\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            do
            {
                printf("Enter ALLOCATION[%d][%d] entry :", i , j);
                scanf("%d", &allocation);    

                if(allocation < 0 )
                    printf("allocation should be >=0\n");
                else
                    ALLOCATION[i][j] = allocation;
            } while (allocation < 0);
        }
    }   
}

// function to max allocation
void acceptRequest()
{
    int request = 0, i, j;
    printf("Enter REQUEST matrix.\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            do
            {
                printf("Enter REQUEST[%d][%d] entry :", i , j);
                scanf("%d", &request);    

                if(request < 0 )
                    printf("request entry should be >=0\n");
                else
                    REQUEST[i][j] = request;
            } while (request < 0);
        }
    }   
}


// function to accept validated AVAILABLE matrix
void acceptAvailable()
{
    int res_count = 0, i;
    printf("Enter resource instances count.\n");
    for(i = 0; i < m; i++)
    {
        do
        {
            printf("Enter number of instances of resources type(%d) :", i + 1);
            scanf("%d", &res_count);    

            if(res_count <= 0)
                printf("Instances should be greater than 0.\n");
            else
                AVAILABLE[i] = res_count;
        } while (res_count <= 0);
    }   

    copy_tuple(AVAILABLE, temp);

    printf("Enter AVAILABLE:\n");
    for(i = 0; i < m; i++)
    {
        do
        {
            printf("AVAILABLE[%d] :", i + 1);
            scanf("%d", &res_count);    

            if(res_count < 0)
                printf("AVAILABLE entry should be greater than or equal to 0.\n");
            else
                AVAILABLE[i] = res_count;
        } while (res_count < 0);
    }   


}

void safety_algo()
{
    int *work = (int *)malloc(sizeof(int) * m), *finish = (int *)malloc(sizeof(int) * n);
    int i, j, c = 0;

    safe_seq = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
        finish[i] = 0;

    copy_tuple(AVAILABLE, work);

    for(i = 0; i < 2*n; i++)
    {
        if(finish[i%n] == 0 && cmp_tuple(REQUEST[i%n], work))
        {
            safe_seq[c++] = i%n;
            finish[i%n] = 1;
            for(j = 0; j < m; j++)
                work[j] += ALLOCATION[i%n][j];
        }
    }

    for(i = 0; i < n; i++)
        if (finish[i] != 1)
            is_safe = 0;
}

// compare if all elements of a are less then respective elements in b 
int cmp_tuple(int *a, int *b)
{
    int i = 0;
    for(i = 0; i <m; i++)
        if(a[i] > b[i])
            return 0;
    return 1;
}

// copy a into b
void copy_tuple(int *a, int *b)
{
    int i = 0;
    for(i = 0; i < m; i++)
        b[i] = a[i];
}




// function to print matrix
void printMatrix(int **mat)
{
    int i, j;
    printf("\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", mat[i][j]);

        printf("\n");
    }
}
