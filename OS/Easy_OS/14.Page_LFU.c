#include <stdio.h>
#include <limits.h>

void LFU(int noPage, int page[], int noFrame, int frame[])
{
    int i, j, count[noFrame], freq[noFrame], hit = 0, fault = 0;
    for (i = 0; i < noFrame; i++)
    {
        frame[i] = -1;
        count[i] = 0;
        freq[i] = INT_MAX;
    }
    printf("Pages\tFrames\t Hit \n");
    for (i = 0; i < noPage; i++)
    {
        int minFreq = INT_MAX, index = -1;
        for (j = 0; j < noFrame; j++)
        {
            if (frame[j] == page[i]) 
            {
                hit++;
                count[j]++;
                freq[j] = count[j];
                break;
            }
            if (frame[j] == -1) 
            {
                frame[j] = page[i];
                count[j]++;
                freq[j] = count[j];
                fault++;
                break;
            }
            if (freq[j] < minFreq) 
            {
                minFreq = freq[j];
                index = j;
            }
        }
        if (j == noFrame) 
        {
            fault++;
            frame[index] = page[i];
            count[index] = 1;
            freq[index] = 1;
        }
        printf("%d \t", page[i]);
        for (j = 0; j < noFrame; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\t %d\n", (hit > i));
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
    LFU(noPages, pages, noFrames, frames);
    return 0;
}
