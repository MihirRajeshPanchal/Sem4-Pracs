#include <stdio.h>

// Process structure
struct Process {
    int pid;        // Process ID
    int burst_time; // Burst time
    int priority;   // Priority (lower value means higher priority)
    int completed;  // Flag to indicate if process has completed execution
};

// Function to find the process with the highest priority
int findHighestPriority(struct Process proc[], int n) {
    int highest = -1;
    int highest_priority = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (proc[i].completed == 0 && proc[i].priority < highest_priority) {
            highest_priority = proc[i].priority;
            highest = i;
        }
    }
    return highest;
}

// Function to execute processes using Priority Scheduling
void priorityScheduling(struct Process proc[], int n) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        int highest = findHighestPriority(proc, n);

        if (highest == -1) {
            time++;
            continue;
        }

        printf("Executing Process %d from time %d to %d\n", proc[highest].pid, time, time + proc[highest].burst_time);
        time += proc[highest].burst_time;
        proc[highest].completed = 1;
        completed++;
    }
}

int main() {
    // Example processes
    struct Process processes[] = {
        {1, 6, 2, 0}, // Process ID, Burst Time, Priority
        {2, 8, 1, 0},
        {3, 7, 3, 0},
        {4, 3, 2, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Priority Scheduling\n");
    printf("Process ID\tBurst Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
    }
    printf("\n");

    // Execute processes using Priority Scheduling
    priorityScheduling(processes, n);

    return 0;
}
