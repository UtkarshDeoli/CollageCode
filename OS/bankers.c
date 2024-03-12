#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int safe_sequence[MAX_PROCESSES];
int work[MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes, num_resources;

void input_data() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the available resources: ");
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources required by each process: \n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the allocated resources for each process: \n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int is_safe_state() {
    for (int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    for (int i = 0; i < num_processes; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < num_processes) {
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == num_resources) {
                    for (int k = 0; k < num_resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            return 0; // Unsafe state
        }
    }
    return 1; // Safe state
}

void display_safe_sequence() {
    printf("Safe sequence: ");
    for (int i = 0; i < num_processes; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");
}

int main() {
    input_data();

    if (is_safe_state()) {
        printf("The system is in a safe state.\n");
        display_safe_sequence();
    } else {
        printf("The system is in an unsafe state.\n");
    }

    return 0;
}
