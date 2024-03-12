#include<stdio.h>
#include<stdlib.h>

struct Process{
    int arrivalTime;
    int brustTime;
    int brustCp;
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
    int complete = 0;
    int time = processess[0].arrivalTime;
    processess[0].WT = 0;
    processess[0].brustTime -= 1;
    time++;
    printf("AT\t\tBT\t\tTAT\t\tWT\n\n");
    while(complete != n)
    {
        int min = -1;
        int index;
        for(int i=0; i<n; i++)
        {
            if(processess[i].arrivalTime <= time && processess[i].brustTime != 0)
            {
                if(min < processess[i].priority)
                {
                    min = processess[i].priority;
                    index = i;
                }
            }
        }
        processess[index].brustTime -= 1;
        time++;
        if(processess[index].brustTime == 0)
        {z
            processess[index].TAT = time - processess[index].arrivalTime;
            processess[index].WT = processess[index].TAT - processess[index].brustCp;
             printf("%d\t\t%d\t\t%d\t\t%d\n",  processess[index].arrivalTime, processess[index].brustCp, processess[index].TAT, processess[index].WT);
            complete++;
        }
    }
}



int main()
{
    int n = 5;

    struct Process processess[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter Arrival Time, Brust Time, and Priority: ");
        scanf("%d %d %d", &processess[i].arrivalTime, &processess[i].brustTime, &processess[i].priority);
        processess[i].brustCp = processess[i].brustTime;
    }

    qsort(processess, n, sizeof(struct Process), compare);
    priority(processess, n);
    return 0;
}