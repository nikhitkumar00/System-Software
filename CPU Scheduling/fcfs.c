#include <stdio.h>
#include <stdlib.h>

void main()
{
      int numberofprocess;
      int i, j, time = 0;
      int arrival[10], burst[10], name[10], complete[10], done[10], turnaround[10], waiting[10];
      float totalturnaround = 0, totalwaiting = 0;

      printf("Enter the number of processess:\n");
      scanf("%d",&numberofprocess);

      printf("Enter the Arrival time, Burst time of processes in order:\n");
      for(i = 0; i < numberofprocess; i++)
      {
            scanf("%d\t%d",&arrival[i],&burst[i]);
            name[i] = i;
      }

      for(i = 0; i < numberofprocess-1; i++)
      {
            for(j = 0; j < numberofprocess-i-1; j++)
            {
                  if(arrival[j] > arrival[j+1])
                  {
                        int temp    =     arrival[j];
                        arrival[j]  =     arrival[j+1];
                        arrival[j+1]=     temp;

                        temp        =     burst[j];
                        burst[j]    =     burst[j+1];
                        burst[j+1]  =     temp;

                        temp        =     name[j];
                        name[j]     =     name[j+1];
                        name[j+1]   =     temp;
                  }
            }
      }

      printf("\n\nName\tArrival\tBurst\tComplete\tTurnAround\tWaiting");

      complete[-1] = 0;
      for(i = 0; i < numberofprocess; i++)
      {
            if(arrival[i] > complete[i-1])
            {
                  complete[i-1] = complete[i-1] + arrival[i];
            }

            complete[i]       = complete[i-1]   +     burst[i];
            turnaround[i]     = complete[i]     -     arrival[i];
            waiting[i]        = turnaround[i]   -     burst[i];
            totalturnaround   = totalturnaround +     turnaround[i];
            totalwaiting      = totalwaiting    +     waiting[i];

            printf("\n%d\t%d\t%d\t%d\t\t%d\t\t%d", name[i], arrival[i], burst[i], complete[i], turnaround[i], waiting[i]);
      }

      printf("\n\nThe Average TurnRound Time is :\t%f",totalturnaround/numberofprocess);
      printf("\nAverage Waiting Time is :\t%f",totalwaiting/numberofprocess);
}
