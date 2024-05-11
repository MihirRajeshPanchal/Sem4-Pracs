#include <stdio.h>
#include <stdbool.h>

// Process structure
struct Process {
    int pid;         // Process ID
    int burst_time;  // Burst time
    int priority;    // Priority (lower value means higher priority)
    int remaining;   // Remaining burst time
    bool completed;  // Flag to indicate if process has completed execution
};

// Function to find the process with the highest priority
int findHighestPriority(struct Process proc[], int n) {
    int highest = -1;
    int highest_priority = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (!proc[i].completed && proc[i].priority < highest_priority) {
            highest_priority = proc[i].priority;
            highest = i;
        }
    }
    return highest;
}

// Function to execute processes using preemptive Priority Scheduling
void priorityScheduling(struct Process proc[], int n) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        int highest = findHighestPriority(proc, n);

        if (highest == -1) {
            time++;
            continue;
        }

        printf("Executing Process %d from time %d to ", proc[highest].pid, time);
        time++;
        proc[highest].remaining--;

        if (proc[highest].remaining == 0) {
            proc[highest].completed = true;
            completed++;
            printf("%d\n", time);
        } else {
            printf("%d (Remaining Burst Time: %d)\n", time, proc[highest].remaining);
        }
    }
}

int main() {
    // Example processes
    struct Process processes[] = {
        {1, 6, 2, 6, false}, // Process ID, Burst Time, Priority, Remaining Burst Time, Completed
        {2, 8, 1, 8, false},
        {3, 7, 3, 7, false},
        {4, 3, 2, 3, false}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Preemptive Priority Scheduling\n");
    printf("Process ID\tBurst Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
    }
    printf("\n");

    // Execute processes using Preemptive Priority Scheduling
    priorityScheduling(processes, n);

    return 0;
}
