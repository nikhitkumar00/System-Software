#include <stdio.h>

void main()
{
      int numberofpages, numberofframes;
      int page[20], frame[20];
      int i, j, k, flag, position = 0, fault = 0;

      printf("Enter the number of Pages that you wish to input:\n");
      scanf("%d",&numberofpages);

      printf("Enter the frame size:\n");
      scanf("%d",&numberofframes);

      printf("Enter the pages in order:\n");
      for(i = 0; i < numberofpages; i++)
      {
            scanf("%d",&page[i]);
            frame[i]    = -1;
      }

      printf("\n\nRequest\t\tFrames\t\t\t\tPage Fault\n");

      for(i = 0; i < numberofpages; i++)
      {
            flag = 0;
            for(k = 0; k < numberofframes; k++)
            {
                  if(frame[k] == page[i])
                  {
                        flag = 1;
                  }
            }

            if(flag == 0)
            {
                  fault++;
                  frame[position] = page[i];
                  position++;

                  if(position == numberofframes)
                  {
                        position = 0;
                  }

                  printf("\n%d\t\t",page[i]);

                  for(j = 0; j < numberofframes; j++)
                  {
                        printf("%d\t",frame[j]);
                  }
                  printf("%d",fault);
            }
            else
            {
                  printf("\n%d\t\t",page[i]);

                  for(j = 0; j < numberofframes; j++)
                  {
                        printf("%d\t",frame[j]);
                  }
                  printf("%d",fault);
            }
      }
      printf("\n\nThe Total number of FAULTS : %d\n\n",fault);
}