#include <stdio.h>


void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    int start_index = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = start_index; i < m; i++)
        {
            if (blockSize[i] >= processSize[j])
            {
                allocation[j] = i;
                blockSize[i] = 0;
                start_index = i;
                break;
            }
            start_index = (start_index + 1) % m;
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t", i + 1);
        printf("%i\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    printf("\n--- Next Fit ---");
    int blockSize3[] = {100, 500, 200, 450, 600};
    int processSize3[] = {212, 417, 112, 426};
    int m = sizeof(blockSize3) / sizeof(blockSize3[0]);
    int n = sizeof(processSize3) / sizeof(processSize3[0]);
    nextFit(blockSize3, m, processSize3, n);
    return 0;
}