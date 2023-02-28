#include <stdio.h>
#include <stdlib.h>

void main()
{
      int name[10], arrival[10], burst[10], complete[10], turnaround[10], waiting[10], done[10], priority[10];
      float totalturnaround, totalwaiting;
      int i, j, k, flag, index, time = 0;
      int numberofprocess;

      printf("Enter the number of process:\n");
      scanf("%d",&numberofprocess);

      printf("Enter the Arrival time and Burst time in order:\n");
      for(i = 0; i < numberofprocess; i++)
      {
            scanf("%d\n%d\n%d",&arrival[i],&burst[i],&priority[i]);
            name[i] = i;
            done[i] = 0;
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

                        temp              =     priority[j];
                        priority[j]       =     priority[j+1];
                        priority[j+1]     =     temp;
                  }
            }
      }

      if(arrival[0] > 0)
      {
            time = arrival[0];
      }

      printf("\n\nName\tArrival\tBurst\tComplete\tPriority\tTurnAround\tWaiting");

      while(1)
      {
            flag = 0;
            for(i = 0; i < numberofprocess; i++)
            {
                  if(done[i] == 0)
                  {
                        flag = 1;
                  }
            }
            if(flag != 1)
            {
                  printf("\n\nProcess completed\n\n");
                  printf("\nAverage Turn Around Time : %f",totalturnaround/numberofprocess);
                  printf("\nAverage Waiting Time : %f",totalwaiting/numberofprocess);
                  exit(0);
            }

            for(i = 0; i < numberofprocess; i++)
            {
                  if(done[i] == 0)
                  {
                        if(arrival[i] <= time)
                        {
                              int small = 1000;
                              for(i = 0; i < numberofprocess; i++)
                              {
                                    if(done[i] == 0)
                                    {
                                          if(arrival[i] <= time)
                                          {
                                                if(small > priority[i])
                                                {
                                                      small = priority[i];
                                                      index = i;
                                                }
                                          }
                                    }
                              }
                              time              =     time              +     burst[index];
                              complete[index]   =     time;
                              turnaround[index] =     complete[index]   -     arrival[index];
                              waiting[index]    =     turnaround[index] -     burst[index];
                              totalturnaround   =     totalturnaround   +     turnaround[index];
                              totalwaiting      =     totalwaiting      +     waiting[index];
                              done[index]       =     1;

                              printf("\n%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d", name[index], arrival[index], burst[index], priority[index], complete[index], turnaround[index], waiting[index]);
                        }
                  }
            }
      }
}