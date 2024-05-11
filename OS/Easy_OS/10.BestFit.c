#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {

        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {

            allocation[i] = bestIdx;

            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    printf("\n--- Best Fit ---");
    int blockSize1[] = {100, 500, 200, 300, 600};
    int processSize1[] = {212, 417, 112, 426};
    int m = sizeof(blockSize1) / sizeof(blockSize1[0]);
    int n = sizeof(processSize1) / sizeof(processSize1[0]);
    bestFit(blockSize1, m, processSize1, n);
}