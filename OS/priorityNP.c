#include<stdio.h>
#include<stdlib.h>

struct Process{
    int arrivalTime;
    int BrustTime;
    int priority;
    int TAT;
    int WT;
};

int compare(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return p1->arrivalTime - p2->arrivalTime;
}

void priority(struct Process *processess, int n)
{
    processess[0].WT = 0;
    processess[0].TAT = processess[0].WT + processess[0].BrustTime;
    int endTime = processess[0].arrivalTime + processess[0].BrustTime;
    int startTime;
    printf("PN\t\tAT\t\tBT\t\tPriority\tTAT\t\tWT\n");
    printf("1\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processess[0].arrivalTime, processess[0].BrustTime, processess[0].priority, processess[0].TAT, processess[0].WT);
    processess[0].BrustTime = 0;
    for(int i=1; i<n; i++)
    {
        int min = -1;
        int index;
        for(int j=0; j<n; j++)
        {
            if(processess[j].arrivalTime <= endTime && processess[j].BrustTime != 0)
            {
                if(min < processess[j].priority)
                {
                    min = processess[j].priority;
                    index = j;
                }
            }
        }
        if(processess[index].arrivalTime > endTime) startTime = processess[index].arrivalTime;
        else startTime = endTime;
        processess[index].WT = startTime - processess[index].arrivalTime;
        endTime = startTime + processess[index].BrustTime;
        processess[index].TAT = processess[index].BrustTime + processess[index].WT;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processess[index].arrivalTime, processess[index].BrustTime, processess[index].priority, processess[index].TAT, processess[index].WT);
        processess[index].BrustTime = 0;
    }
}

int main()
{
    int n = 5;
    struct Process processess[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter Arrival Time, Brust Time and Priority: ");
        scanf("%d %d %d", &processess[i].arrivalTime, &processess[i].BrustTime, &processess[i].priority);
    }

    qsort(processess, n, sizeof(struct Process), compare);
    priority(processess, n);

    return 0;
}