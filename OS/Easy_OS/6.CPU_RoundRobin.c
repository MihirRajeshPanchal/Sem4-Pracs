#include <stdio.h>
#include <stdlib.h>

#define TIME_QUANTUM 2 

struct Processes {
    int process_id;
    int at;
    int bt;
    int ct;
    int tat;
    int remaining_bt;
};

void RoundRobin(struct Processes *process, int n) {
    int current_time = 0;
    int *remaining_time = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        remaining_time[i] = process[i].bt;
    }

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;

                if (remaining_time[i] > TIME_QUANTUM) {
                    current_time += TIME_QUANTUM;
                    remaining_time[i] -= TIME_QUANTUM;
                } else {
                    current_time += remaining_time[i];
                    process[i].ct = current_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (done == 1) 
            break;
    }

    free(remaining_time);

    for (int i = 0; i < n; i++) {
        process[i].tat = process[i].ct - process[i].at;
    }
}

void printResults(struct Processes *process, int n) {
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", process[i].process_id, process[i].at, process[i].bt, process[i].ct, process[i].tat);
    }
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
        {1, 0, 4, 0, 0, 0},
        {2, 1, 3, 0, 0, 0},
        {3, 2, 5, 0, 0, 0},
        {4, 3, 2, 0, 0, 0},
        {5, 4, 1, 0, 0, 0}
    };

    RoundRobin(process, n);
    printResults(process, n);

    return 0;
}
