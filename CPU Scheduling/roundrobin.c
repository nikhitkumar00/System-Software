#include <stdio.h>
#include <stdlib.h>

void main()
{
      int numberofprocess, splice;
      int i, j, time = 0, flag;
      int arrival[10], burst[10], name[10], complete[10], done[10], turnaround[10], waiting[10], temp[10];
      float totalturnaround = 0, totalwaiting = 0;

      printf("Enter the number of processess:\n");
      scanf("%d",&numberofprocess);

      printf("Enter the Time Splice:\n");
      scanf("%d",&splice);

      printf("Enter the Arrival time, Burst time of processes in order:\n");
      for(i = 0; i < numberofprocess; i++)
      {
            scanf("%d\t%d",&arrival[i],&burst[i]);
            name[i] = i;
            done[i] = 0;
            temp[i] = burst[i];
      }

      for(i = 0; i < numberofprocess-1; i++)
      {
            for(j = 0; j < numberofprocess-i-1; j++)
            {
                  if(arrival[j] > arrival[j+1])
                  {
                        int tempp    =     arrival[j];
                        arrival[j]  =     arrival[j+1];
                        arrival[j+1]=     tempp;

                        tempp       =     burst[j];
                        burst[j]    =     burst[j+1];
                        burst[j+1]  =     tempp;

                        tempp        =     name[j];
                        name[j]     =     name[j+1];
                        name[j+1]   =     tempp;
                  }
            }
      }

      printf("\n\nName\tArrival\tBurst\tComplete\tTurnAround\tWaiting");
      
      time = 0;
      
      for(j = 0; j < numberofprocess; j++)
      {
            for(i = 0; i < numberofprocess; i++)
            {
                  if(done[i] == 0)
                  {
                        if(arrival[i] > time)
                        {
                              time = time + arrival[i];
                        }

                        if(temp[i] <= splice)
                        {
                              time = time + temp[i];
                              complete[i] = time;
                              turnaround[i] = complete[i] - arrival[i];
                              waiting[i] = turnaround[i] - burst[i];
                              totalturnaround = totalturnaround + turnaround[i];
                              totalwaiting = totalwaiting + waiting[i];
                              done[i] = 1;

                              printf("\n%d\t%d\t%d\t%d\t\t%d\t\t%d", name[i], arrival[i], burst[i], complete[i], turnaround[i], waiting[i]);

                        }
                        else
                        {
                              time = time + splice;
                              temp[i] = temp[i] - splice;
                        }
                  }
            }
      }
      printf("\n\nProcess completed\n\n");
      printf("\nAverage Turn Around Time : %f",totalturnaround/numberofprocess);
      printf("\nAverage Waiting Time : %f",totalwaiting/numberofprocess);
}