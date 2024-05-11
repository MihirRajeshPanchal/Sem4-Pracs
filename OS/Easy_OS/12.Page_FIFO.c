#include <stdio.h>

void Fifo(int noPage, int page[], int noFrame, int frame[])
{
    int i, j, framehead = 0, hitCount = 0, faultCount = 0;
    for (i = 0; i < noFrame; i++)
    {
        frame[i] = -1;
    }
    printf("Pages\tFrames\t Hit \n");
    for (i = 0; i < noPage; i++)
    {
        int count = 0;
        int hit = 0;
        for (j = 0; j < noFrame; j++)
        {
            if (frame[j] != page[i])
            {
                count++;
            }
            else
            {
                hit = 1;
                hitCount++;
                break;
            }
        }
        if (i < noFrame)
        {
            frame[faultCount] = page[i];
            faultCount++;
        }
        else if (count == noFrame)
        {
            frame[framehead] = page[i];
            faultCount++;
            framehead = (framehead + 1) % noFrame;
        }

        printf("%d \t", page[i]);
        for (j = 0; j < noFrame; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\t %d\n", hit);
    }
    float hitPercent = ((float)hitCount / noPage) * 100;
    float faultPercent = ((float)faultCount / noPage) * 100;
    printf("Page Faults: %d\n", faultCount);
    printf("Hits: %d\n", hitCount);
    printf("Hit Percent: %.2f%%\n", hitPercent);
    printf("Fault Percent: %.2f%%\n", faultPercent);
}

int main()
{
    // int noPages, ch;
    // printf("Enter number of pages: ");
    // scanf("%d", &noPages);
    // int pages[noPages];
    // printf("Enter the sequence: ");
    // for (int i = 0; i < noPages; i++)
    // {
    //     scanf("%d", &pages[i]);
    // }
    // int noFrames;
    // printf("Enter number of frames: ");
    // scanf("%d", &noFrames);
    // int frames[noFrames];

    int pages[] = {2, 3, 4, 2, 1, 3, 7, 5, 4, 3};
    int noPages = sizeof(pages) / sizeof(pages[0]);
    
    int noFrames = 3;
    int frames[noFrames];

    Fifo(noPages, pages, noFrames, frames);
}
