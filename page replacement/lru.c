#include <stdio.h>

void main()
{
      int numberofpages, numberofframes;
      int page[20], frame[20], status[20];
      int i, j, k, flag, small, position, fault = 0, recent = 1, index;

      printf("Enter the number of pages:\n");
      scanf("%d",&numberofpages);

      printf("Enter the number of frames:\n");
      scanf("%d",&numberofframes);

      printf("Enter the pages in order:\n");
      for(i = 0; i < numberofpages; i++)
      {
            scanf("%d",&page[i]);
            frame[i]    = -1;
            status[i]   = 0;
      }

      printf("\n\nRequest\t\tFrames\t\t\t\tPage Fault\n");

      for(i = 0; i < numberofpages; i++)
      {
            flag = 0;
            for(k = 0; k < numberofframes; k++)
            {
                  if(frame[k] == page[i])
                  {
                        flag  = 1;
                        index = k;
                  }
            }

            if(flag == 0)
            {
                  fault++;
                  small = 100;
                  for(j = 0; j < numberofframes; j++)
                  {
                        if(small > status[j])
                        {
                              small = status[j];
                              position = j;
                        }
                  }
                  
                  frame[position]   = page[i];
                  status[position]  = recent;
                  recent++;

                  printf("\n%d\t\t",page[i]);

                  for(k = 0; k < numberofframes; k++)
                  {
                        printf("%d\t",frame[k]);
                  }

                  printf("%d",fault);
            }

            else
            {
                  status[index] = recent;
                  recent++;
                  
                  printf("\n%d\t\t",page[i]);

                  for(k = 0; k < numberofframes; k++)
                  {
                        printf("%d\t",frame[k]);
                  }

                  printf("%d",fault);
            }
      }
}