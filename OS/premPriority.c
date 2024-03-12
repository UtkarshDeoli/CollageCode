#include <stdio.h>

typedef struct {
    int pid;
    int priority;
    int burst_time;
    int resource_needed;
} Process;

int findHighestPriority(Process processes[], int n) {
    int highest_priority = processes[0].priority;
    int highest_priority_index = 0;

    for (int i = 1; i < n; i++) {
        if (processes[i].priority < highest_priority) {
            highest_priority = processes[i].priority;
            highest_priority_index = i;
        }
    }

    return highest_priority_index;
}

void preemptivePriorityScheduling(Process processes[], int n) {
    int total_time = 0;
    int completed = 0;

    while (completed < n) {
        int highest_priority_index = findHighestPriority(processes, n);

        if (processes[highest_priority_index].burst_time > 0) {
            printf("Executing process with PID %d\n", processes[highest_priority_index].pid);
            processes[highest_priority_index].burst_time--;
            total_time++;
        }

        if (processes[highest_priority_index].burst_time == 0) {
            printf("Process with PID %d completed\n", processes[highest_priority_index].pid);
            completed++;
        }
    }

    printf("Total execution time: %d\n", total_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the resource needed for process %d: ", i + 1);
        scanf("%d", &processes[i].resource_needed);
        processes[i].pid = i + 1;
    }

    preemptivePriorityScheduling(processes, n);

    return 0;
}
