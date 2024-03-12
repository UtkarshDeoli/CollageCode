#include <stdio.h>
#include<stdlib.h>

struct Process {
    int arrivalTime;
    int burstTime;
    int waitTime;
    int endTime;
    int TAT;
};

int compare(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return p1->arrivalTime - p2->arrivalTime;
}

void CalculateWaitingTime(struct Process *processes, int N)
{

    processes[0].waitTime = 0;
    processes[0].endTime = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].TAT = processes[0].burstTime + processes[0].waitTime;
    printf("PN\t\tAT\t\tBT\t\tTAT\t\tWT\n\n");
    printf("1\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[0].arrivalTime, processes[0].burstTime, processes[0].TAT, processes[0].waitTime);

    for (int i = 1; i < 5; i++)
    {
        int startTime;
        if(processes[i-1].endTime > processes[i].arrivalTime)
        {
            startTime = processes[i-1].endTime;
        }
        else{
            startTime = processes[i].arrivalTime;
        }
        processes[i].waitTime = startTime - processes[i].arrivalTime;
        processes[i].endTime = startTime + processes[i].burstTime;
        processes[i].TAT = processes[i].burstTime + processes[i].waitTime;


        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrivalTime, processes[i].burstTime, processes[i].TAT, processes[i].waitTime);
    }


    float average;
    float sum = 0;


    for (int i = 0; i < 5; i++)
    {
        sum = sum + processes[i].waitTime;
    }

  
    average = sum / 5;

    // Print Average Waiting Time
    printf("\nAverage waiting time = %.2f\n", average);
}

// Driver code
int main()
{

    int N = 5;


    struct Process processes[N];

    for(int i=0; i<N; i++)
    {
        printf("Enter Arrival Time and Burst Time: ");
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }

    qsort(processes, N, sizeof(struct Process), compare);

    CalculateWaitingTime(processes, N);
    return 0;
}
