#include <stdio.h>
#include <limits.h>
#include<stdlib.h>

typedef struct nppq
{
    int pid;
    int at;
    int bt;
    int pri;
    int wt;
    int tat;
    int ct;
    int comp;
} p;

int main()
{
    int n;
    printf("Enter the number of process:\n");
    scanf("%d", &n);

    p *process = (p *)malloc(n * sizeof(p));
  

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival, burst times, and priority of process %d :", i + 1);
        scanf("%d %d %d", &process[i].at, &process[i].bt, &process[i].pri);
        process[i].pid = i + 1;
        process[i].comp = 0;
    }

    int cur = 0;
    long long totalWT = 0, totalTAT = 0;
    for (int j=0;j<n;j++)
    {
        int maxPri = INT_MAX;
        int maxPos = -1;
        for (int i = 0; i < n; i++)
        {
            if (process[i].at <= cur && process[i].pri < maxPri && process[i].comp == 0)
            {
                maxPri = process[i].pri;
                maxPos = i;
            }
        }
        if (maxPos == -1)
        {
            cur++;
            continue;
        }
        else
        {
            cur += process[maxPos].bt;
            process[maxPos].ct = cur;
            process[maxPos].tat = process[maxPos].ct - process[maxPos].at;
            process[maxPos].wt = process[maxPos].tat - process[maxPos].bt;

            totalTAT += process[maxPos].tat;
            totalWT += process[maxPos].wt;
            process[maxPos].comp = 1;
        }
    }

    printf("PID\tAT\tBT\tPRI\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d", process[i].pid, process[i].at, process[i].bt, process[i].pri, process[i].wt, process[i].tat);
        printf("\n");
    }
    float atat = totalTAT * 1.0 / n;
    float awt = totalWT * 1.0 / n;

    printf("ATAT:%f\n", atat);
    printf("WT:%f\n", awt);

    free(process);
    return 0;
}
