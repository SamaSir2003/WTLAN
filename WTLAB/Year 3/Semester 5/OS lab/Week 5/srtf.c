#include <stdio.h>

int main()
{
      int arrival_time[10], burst_time[10], temp[10],wt[10],tat[10];
      int i, smallest, count = 0, time, n;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;

      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n);
      printf("\nEnter Details of %d Processesn", n);

      for (i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]);
            temp[i] = burst_time[i];
      }

      burst_time[9] = 9999;

      for (time = 0; count != n; time++)
      {
            smallest = 9;

            for (i = 0; i < n; i++)
            {
                  if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }

            burst_time[smallest]--;

            if (burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wt[smallest]=end - arrival_time[smallest] - temp[smallest];

                  wait_time +=wt[smallest];
                  tat[smallest]= end - arrival_time[smallest];

                  turnaround_time +=tat[smallest];
            }
      }

      average_waiting_time = wait_time / n;
      average_turnaround_time = turnaround_time / n;

      printf("P\tAt\tBt\tWt\tTat\t\n");

      for(int i=0;i<n;i++){
            printf("%d\t%d\t%d\t%d\t%d\t\n",i,arrival_time[i],temp[i],wt[i],tat[i]);

      
      
      }
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);

      return 0;
}
