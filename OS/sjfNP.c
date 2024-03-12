#include<stdio.h>
#include<stdlib.h>


struct Process {
    int arrivalTime;
    int brustTime;
    int TAT;
    int WT;
};


int compare(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return p1->arrivalTime - p2->arrivalTime;
}


void sjf(struct Process *processes, int n)
{
    processes[0].WT = 0;
    int startTime = processes[0].arrivalTime;
    int endTime = startTime + processes[0].brustTime;
    processes[0].TAT = processes[0].brustTime + processes[0].WT;
    printf("PN\t\tAT\t\tBT\t\tTAT\t\tWT\n\n");
    printf("1\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[0].arrivalTime, processes[0].brustTime, processes[0].TAT, processes[0].WT);
    processes[0].brustTime = 0;
    for(int i=1; i<n; i++)
    {
        int min = 24234;
        int index;
        for(int j=0; j<n; j++)
        {
            if(processes[j].arrivalTime <= endTime && processes[j].brustTime != 0)
            {
                if(processes[j].brustTime < min)
                {
                    min = processes[j].brustTime;
                    index = j;
                } 
            }
        }

        if(processes[index].arrivalTime > endTime) startTime = processes[index].arrivalTime;
        else startTime = endTime;
        processes[index].WT = startTime - processes[index].arrivalTime;
        endTime = startTime + processes[index].brustTime;
        processes[index].TAT = processes[index].WT + processes[index].brustTime;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[index].arrivalTime, processes[index].brustTime, processes[index].TAT, processes[index].WT);
        processes[index].brustTime = 0;
    }
}

int main()
{
    int n = 5;

    struct Process processes[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter Arrival Time and Brust Time: ");
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].brustTime);
    }

    qsort(processes, n, sizeof(struct Process), compare);
    sjf(processes, n);
    return 0;
}