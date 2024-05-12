#include <stdio.h>

// Function to calculate the absolute difference between two integers
int absolute(int a, int b)
{
    if (a >= b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}

// Function to implement Shortest Seek Time First (SSTF) disk scheduling algorithm
int shortestSeekTimeFirst(int numMovements, int currentHead, int movements[], int answer[])
{
    int totalSeekTime = 0;
    int currentPosition, visited[numMovements];
    for (int i = 0; i < numMovements; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < numMovements; i++)
    {
        if (i == 0)
        {
            currentPosition = currentHead;
        }
        else
        {
            currentPosition = answer[i - 1];
        }
        int minDistance = 199, selectedMovementIndex, temp;
        for (int j = 0; j < numMovements; j++)
        {
            if (absolute(currentPosition, movements[j]) <= minDistance && visited[j] == 0)
            {
                minDistance = absolute(currentPosition, movements[j]);
                selectedMovementIndex = j;
            }
        }
        visited[selectedMovementIndex] = 1;
        totalSeekTime += minDistance;
        answer[i] = movements[selectedMovementIndex];
    }

    return totalSeekTime;
}

// Function to print the movements and total seek time
void printMovements(int numMovements, int currentHead, int answer[], int totalSeekTime)
{
    printf("\nTrack movements are as follows: \n");
    printf("%d -> %d", currentHead, answer[0]);
    for (int i = 1; i < numMovements; i++)
    {
        printf(" -> %d", answer[i]);
    }

    printf("\nTotal seek time is: %d\n", totalSeekTime);
}

int main()
{
    // int numMovements, currentHead;
    // printf("\nEnter the number of movements: ");
    // scanf("%d", &numMovements);

    // int movements[numMovements];
    // printf("\nEnter %d movements (0 - 199): ", numMovements);
    // for (int i = 0; i < numMovements; i++)
    // {
    //     scanf("%d", &movements[i]);
    // }

    // printf("\nEnter the current head location: ");
    // scanf("%d", &currentHead);

    int numMovements = 5, currentHead = 65;
    int movements[] = {25, 51, 60, 132, 189};
    int totalSeekTime, answer[numMovements];
    totalSeekTime = shortestSeekTimeFirst(numMovements, currentHead, movements, answer);
    printMovements(numMovements, currentHead, answer, totalSeekTime);
}
