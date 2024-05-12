#include <stdio.h>
#include <stdlib.h>

#define TIME_QUANTUM 2 

struct Processes {
    int process_id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int compare(const void* a, const void* b){
    return ((struct Processes *)a)->at - ((struct Processes *)b)->at;
}

void RoundRobin(struct Processes *process, int n) {
    qsort(process,n,sizeof(struct Processes),compare);
    int current_time = 0;
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = process[i].bt;
    }

    while (1)
    {
        int done = 1;
        for(int i = 0; i<n; i++){
            if(remaining_time[i] > 0){
                done = 0;

                if(remaining_time[i]> TIME_QUANTUM){
                    current_time += TIME_QUANTUM;
                    remaining_time[i] -= TIME_QUANTUM;
                }
                else{
                    current_time += remaining_time[i];
                    process[i].ct = current_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if(done==1){
            break;
        }

        for (int i = 0; i < n; i++) {
            process[i].tat = process[i].ct - process[i].at;
            process[i].wt = process[i].tat - process[i].bt;
        }
    }
    

}

void printResults(struct Processes *process, int n) {
    int total_tat = 0, total_wt = 0;

    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", process[i].process_id, process[i].at, process[i].bt, process[i].ct, process[i].tat, process[i].wt);
        total_tat += process[i].tat;
        total_wt += process[i].wt;
    }

    printf("\nAverage Turn Around Time: %.2f", (float)total_tat / n);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
}
int main() {
    // int n;

    // printf("Enter Number of Processes: ");
    // scanf("%d", &n);

    // struct Processes process[n];

    // for (int i = 0; i < n; i++) {
    //     process[i].process_id = i + 1;
    //     printf("Enter Arrival Time of Process %d: ", i + 1);
    //     scanf("%d", &process[i].at);

    //     printf("Enter Burst Time of Process %d: ", i + 1);
    //     scanf("%d", &process[i].bt);
    // }

    int n = 5;
    struct Processes process[5] = {
        {1, 5, 4, 0, 0},
        {2, 1, 3, 0, 0},
        {3, 2, 5, 0, 0},
        {4, 3, 2, 0, 0},
        {5, 4, 1, 0, 0}
    };

    RoundRobin(process, n);
    printResults(process, n);

    return 0;
}
