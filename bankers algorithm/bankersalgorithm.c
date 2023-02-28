#include <stdio.h>

void main()
{
      int numberofprocess, numberofresource;
      int i, j, k, l, flag;
      int available[10], need[20][10], allocated[20][10], maximum[20][10], done[20];


      printf("\nEnter the number of processes that you wish to enter:\n");
      scanf("%d",&numberofprocess);

      printf("\nEnter the number of resource:\n");
      scanf("%d",&numberofresource);

      printf("\nEnter the available matrix:\n");
      for(i = 0; i < numberofresource; i++)
      {
            scanf("%d",&available[i]);
      }

      printf("\nEnter the allocated matrix:\n");
      for(i = 0; i < numberofprocess; i++)
      {
            for(j = 0; j < numberofresource; j++)
            {
                  scanf("%d",&allocated[i][j]);
                  done[i] = 0;
            }
      }

      printf("\nEnter the maximum matrix:\n");
      for(i = 0; i < numberofprocess; i++)
      {
            for(j = 0; j < numberofresource; j++)
            {
                  scanf("%d",&maximum[i][j]);
            }
      }

      printf("\nNeed matrix:\n");
      for(i = 0; i < numberofprocess; i++)
      {
            for(j = 0; j < numberofresource; j++)
            {
                  need[i][j] = maximum[i][j] - allocated[i][j];
                  printf("%d  ",need[i][j]);
            }
            printf("\n");
      }

      printf("\n\nThe order of execution will be :\n");
      for(i = 0; i < numberofprocess; i++)
      {
            for(j = 0; j < numberofprocess; j++)
            {
                  if(done[j] == 0)
                  {
                        flag = 0;
                        for(k = 0; k < numberofresource; k++)
                        {
                              if(available[k] >= need[j][k])
                              {
                                    flag++;                                    
                              }

                              if(flag == numberofresource)
                              {
                                    done[j] = 1;
                                    printf("Process[%d]\n",j);

                                    for(l = 0; l < numberofresource; l++)
                                    {
                                          available[l] += allocated[j][l];
                                    }
                              }
                        }
                  }
            }
      }

      flag = 0;
      for(i = 0; i < numberofprocess; i++)
      {
            if(done[i]==1)
            {
                  flag++;
            }
      }
      if(flag == numberofprocess)
      {
            printf("\n\nThe process is in safe state\n\n");
      }
      else
      {
            printf("\n\nThe process is not in safe state\n\n");
      }
}