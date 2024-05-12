#include <stdio.h>

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocatedIndex[m];
    int allocatedProcess[m];
    int fragment[m];
    int lastIndex = 0;
    for(int i = 0; i<m; i++){
        allocatedIndex[i] = -1;
        allocatedProcess[i] = -1;
        fragment[i] = -1;
    }

    for(int i=0; i<n; i++){
        int j = lastIndex;
        do{
            if(blockSize[j]>= processSize[i] && allocatedIndex[j]==-1){
                allocatedIndex[j] = i;
                allocatedProcess[j] = processSize[i];
                fragment[j] = blockSize[j] - processSize[i];
                break;
            }
            j = (j+1)%m;
        }while(j!=lastIndex);
    }
    printf("Block Number\t\t\t Block Size\t\t\t Process Id\t\t\t Process Size\t\t\t Fragmentation\n");
    for(int i=0; i<m; i++){
        printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\n",i+1,blockSize[i],allocatedIndex[i],allocatedProcess[i],fragment[i]);
    }
}


int main()
{
    printf("\n --- Next Fit ---");
    int blockSize[] = {100, 500, 200, 450, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    nextFit(blockSize, m, processSize, n);
}