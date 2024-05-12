#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocatedIndex[m];
    int allocatedProcess[m];
    int fragment[m];
    for(int i = 0; i<m; i++){
        allocatedIndex[i] = -1;
        allocatedProcess[i] = -1;
        fragment[i] = -1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j < m; j++){
            if(blockSize[j]>= processSize[i] && allocatedIndex[j]==-1){
                allocatedIndex[j] = i;
                allocatedProcess[j] = processSize[i];
                fragment[j] = blockSize[j] - processSize[i];
                break;
            }
        }
    }
    printf("Printing Results\n");
    printf("Block Number\t\t\t Block Size\t\t\t Process Id\t\t\t Process Size\t\t\t Fragmentation\n");
    for(int i=0; i<m; i++){
        printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\n",i+1,blockSize[i],allocatedIndex[i],allocatedProcess[i],fragment[i]);
    }
}


int main()
{
    printf("\n --- First Fit ---");
    int blockSize[] = {100, 500, 200, 450, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    firstFit(blockSize, m, processSize, n);
}