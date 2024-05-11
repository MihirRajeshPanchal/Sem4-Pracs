#include <stdio.h>

void LRU(int noPage, int page[], int noFrame, int frame[])
{
    int i, j, timestamp[noFrame], hit = 0, fault = 0, res = 0;
    for (i = 0; i < noFrame; i++)
    {
        frame[i] = -1;
        timestamp[i] = -1;
    }
    printf("Pages\tFrames\t Hit \n");
    for (i = 0; i < noPage; i++)
    {
        int count = 0;
        res = 0; 
        for (j = 0; j < noFrame; j++)
        {
            if (frame[j] != -1) 
            {
                if (frame[j] != page[i])
                {
                    count++;
                }
                else
                {
                    hit++;
                    res = 1;
                    timestamp[j] = i; 
                }
            }
            else 
            {
                frame[j] = page[i];
                fault++;
                timestamp[j] = i;
                res = 0; 
                break;
            }
        }
        if (count == noFrame) 
        {
            fault++;
            int min = 999999, minEle;
            for (j = 0; j < noFrame; j++)
            {
                if (timestamp[j] < min)
                {
                    min = timestamp[j];
                    minEle = j;
                }
            }
            frame[minEle] = page[i];
            timestamp[minEle] = i;
        }
        printf("%d \t", page[i]);
        for (j = 0; j < noFrame; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\t %d\n", res);
    }
    printf("Page Faults : %d \n", fault);
    printf("Hits : %d \n", hit);
}

int main()
{
    int pages[] = {2, 3, 4, 2, 1, 3, 7, 5, 4, 3};
    int noPages = sizeof(pages) / sizeof(pages[0]);
    
    int noFrames = 3;
    int frames[noFrames];
    LRU(noPages, pages, noFrames, frames);
    return 0;
}
