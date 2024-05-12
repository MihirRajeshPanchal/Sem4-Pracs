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

int lookAlgorithm(int numMovements, int currentPosition, int movements[], int result[], int upDirection)
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
    if (upDirection == 0)
    {
        currentMovementIndex--;
    }

    for (int i = 0; i < numMovements; i++)
    {
        if (upDirection == 1)
        {
            if (currentMovementIndex < numMovements && currentMovementIndex >= startPoint)
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex++;
                if (currentMovementIndex == numMovements)
                {
                    currentMovementIndex = currentMovementIndex - startPoint;
                }
            }
            else
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex--;
            }
        }
        else
        {
            if (currentMovementIndex >= 0 && currentMovementIndex < startPoint)
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex--;
                if (currentMovementIndex == -1)
                {
                    currentMovementIndex = startPoint;
                }
            }
            else
            {
                result[i] = movements[currentMovementIndex];
                currentMovementIndex++;
            }
        }
    }

    if (upDirection == 1)
    {
        totalSeekTime = absolute(movements[numMovements - 1], currentPosition) + absolute(movements[numMovements - 1], movements[0]);
    }
    else
    {
        totalSeekTime = absolute(movements[0], currentPosition) + absolute(movements[0], movements[numMovements - 1]);
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
    int upDirection = 1;
    totalSeekTime = lookAlgorithm(numMovements, currentPosition, movements, result, upDirection);
    printResult(numMovements, currentPosition, result, totalSeekTime);
}
