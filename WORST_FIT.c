#include <stdio.h>
void BestFit(int blocks[], int m, int process[], int n)
{
    int allocation[10];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
     for (int i = 0; i < n; i++)
    {
        int bestFit = -1;
        
        for (int j = 0; j < m; j++)
        {
            if (blocks[j] >= process[i])
            {
                if (bestFit == -1 || blocks[j] > blocks[bestFit])
                    bestFit = j;
            }
        }
        if (bestFit!= -1)
        {
            allocation[i] = bestFit;
            blocks[bestFit] -= process[i];
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blocks[10];
    int process[10];
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the size of process %d: ",i+1);
        scanf("%d", &process[i]);
    }

    BestFit(blocks, m, process, n);

    return 0;
}

