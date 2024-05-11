#include <stdio.h>

// Process structure
struct Process {
    int pid;        // Process ID
    int burst_time; // Burst time
    int remaining;  // Remaining burst time
};

// Function to find the process with the shortest remaining time
int findShortestProcess(struct Process proc[], int n) {
    int shortest = -1;
    int shortest_time = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (proc[i].remaining > 0 && proc[i].remaining < shortest_time) {
            shortest_time = proc[i].remaining;
            shortest = i;
        }
    }
    return shortest;
}

// Function to execute processes using SRTF
void SRTF(struct Process proc[], int n) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = findShortestProcess(proc, n);

        if (shortest == -1) {
            time++;
            continue;
        }

        proc[shortest].remaining--;

        if (proc[shortest].remaining == 0) {
            completed++;
            printf("Process %d completed at time %d\n", proc[shortest].pid, time + 1);
        }

        time++;
    }
}

int main() {
    // Example processes
    struct Process processes[] = {
        {1, 6, 6},
        {2, 8, 8},
        {3, 7, 7},
        {4, 3, 3}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Shortest Remaining Time First (SRTF) Scheduling\n");
    printf("Process ID\tBurst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\n", processes[i].pid, processes[i].burst_time);
    }
    printf("\n");

    // Execute processes using SRTF
    SRTF(processes, n);

    return 0;
}
