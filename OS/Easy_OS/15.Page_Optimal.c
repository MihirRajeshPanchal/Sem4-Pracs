#include <stdio.h>
#include <stdbool.h>

void Optimal(int noPage, int page[], int noFrame, int frame[])
{
    int oldest_page_index = 0, hit = 0;
    int fault = 0;

    for (int i = 0; i < noFrame; i++)
    {
        frame[i] = -1;
    }
    for (int i = 0; i < noPage; i++)
    {
        bool found = false;
        bool empty = false;
        for (int j = 0; j < noFrame; j++)
        {
            if (frame[j] == -1)
            {
                empty = true;
                frame[j] = page[i];
                found = true;
                fault++;
                break;
            }
            if (frame[j] == page[i])
            {
                hit++;
                found = true;
                break;
            }
        }
        if (!found && !empty)
        {
            fault++;
            frame[oldest_page_index] = page[i];
            oldest_page_index = (oldest_page_index + 1) % noFrame;
        }
        printf("Page %d: [", page[i]);
        for (int j = 0; j < noFrame; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("] Page Faults: %d\n", fault);
        }
}

int main()
{
    int pages[] = {2, 3, 4, 2, 1, 3, 7, 5, 4, 3};
    int noPages = sizeof(pages) / sizeof(pages[0]);
    
    int noFrames = 3;
    int frames[noFrames];
    Optimal(noPages, pages, noFrames, frames);
    return 0;
}
