#include <stdio.h>

int absolute(int first, int second)
{
    if (first >= second)
    {
        return first - second;
    }
    else
    {
        return second - first;
    }
}

int circularScan(int numMovements, int currentPosition, int movements[], int result[], int direction)
{
    int totalSeekTime = 0;
    int currentMovementIndex, startPoint;
    for (int i = 0; i < numMovements; i++)
    {
        if (currentPosition < movements[i])
        {
            currentMovementIndex = startPoint = i;
            break;
        }
    }
    if (direction == 0)
    {
        currentMovementIndex--;
    }

    for (int i = 0; i < numMovements + 2; i++)
    {
        if (direction == 1)
        {
            if (currentMovementIndex < numMovements && currentMovementIndex >= startPoint)
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex++;
            }
            else if (currentMovementIndex == numMovements)
            {
                result[i] = 199;
                currentMovementIndex = -1;
            }
            else if (currentMovementIndex == -1)
            {
                result[i] = 0;
                currentMovementIndex++;
            }
            else
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex++;
            }
        }
        else
        {
            if (currentMovementIndex >= 0 && currentMovementIndex < startPoint)
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex--;
            }
            else if (currentMovementIndex == -1)
            {
                result[i] = 0;
                currentMovementIndex = numMovements;
            }
            else if (currentMovementIndex == numMovements)
            {
                result[i] = 199;
                currentMovementIndex--;
            }
            else
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex--;
            }
        }
    }

    if (direction == 1)
    {
        totalSeekTime = absolute(199, currentPosition) + 199 + absolute(0, movements[startPoint - 1]);
    }
    else
    {
        totalSeekTime = absolute(0, currentPosition) + 199 + absolute(199, movements[startPoint]);
    }

    return totalSeekTime;
}

void printResult(int numMovements, int currentPosition, int result[], int totalSeekTime)
{
    printf("\nTrack movements are as follows : \n");
    printf("%d -> %d", currentPosition, result[0]);
    for (int i = 1; i < numMovements; i++)
    {
        printf(" -> %d", result[i]);
    }

    printf("\nTotal seek time is : %d\n", totalSeekTime);
}

int main()
{
    // int numMovements, currentPosition;
    // printf("\nEnter the number of movements : ");
    // scanf("%d", &numMovements);

    // int movements[numMovements];
    // printf("\nEnter %d movements (0 - 199) : ", numMovements);
    // for (int i = 0; i < numMovements; i++)
    // {
    //     scanf("%d", &movements[i]);
    // }

    // printf("\nEnter the current head location : ");
    // scanf("%d", &currentPosition);


    int numMovements = 5;
    int currentPosition = 65;
    int movements[] = {25, 51, 60, 132, 189};
    int totalSeekTime, result[numMovements];
    int direction;
    int clockwiseDirection = 0;
    totalSeekTime = circularScan(numMovements, currentPosition, movements, result, clockwiseDirection);
    printResult(numMovements + 2, currentPosition, result, totalSeekTime);
}
