#include <stdio.h>
#include <stdlib.h>

struct Processes {
    int process_id;
    int at;
    int bt;
    int priority;
    int ct;
    int tat;
};

int compareArrival(const void *a, const void *b) {
    return ((struct Processes *)a)->at - ((struct Processes *)b)->at;
}

int comparePriority(const void *a, const void *b) {
    return ((struct Processes *)a)->priority - ((struct Processes *)b)->priority;
}

void PriorityScheduling(struct Processes *process, int n) {
    qsort(process, n, sizeof(struct Processes), compareArrival);

    int current_time = process[0].at;
    for (int i = 0; i < n; i++) {
        if (current_time < process[i].at) {
            current_time = process[i].at;
        }

        int highestPriority = i;
        for (int j = i + 1; j < n; j++) {
            if (process[j].at <= current_time && process[j].priority < process[highestPriority].priority) {
                highestPriority = j;
            }
        }

        struct Processes temp = process[i];
        process[i] = process[highestPriority];
        process[highestPriority] = temp;

        process[i].ct = current_time + process[i].bt;
        current_time = process[i].ct;
        process[i].tat = process[i].ct - process[i].at;
    }
}

void printResults(struct Processes *process, int n) {
    printf("Process\t Arrival Time\t Burst Time\t Priority\t Completion Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", process[i].process_id, process[i].at, process[i].bt, process[i].priority, process[i].ct, process[i].tat);
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

    //     printf("Enter Priority of Process %d: ", i + 1);
    //     scanf("%d", &process[i].priority);
    // }
    int n = 5;
    struct Processes process[5] = {
        {1, 0, 2, 3, 0, 0},
        {2, 0, 7, 2, 0, 0},
        {3, 1, 1, 4, 0, 0},
        {4, 2, 6, 1, 0, 0},
        {5, 5, 9, 5, 0, 0}
    };
    PriorityScheduling(process, n);
    printResults(process, n);

    return 0;
}
