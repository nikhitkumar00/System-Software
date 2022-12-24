#include <stdio.h>
int numberofprocess,time=0;
int name[10],arrival[10],burst[10],complete[10],turnaround[10],waiting[10],done[10];
float totalturnaround=0,totalwaiting=0;

void main()
{
	printf("Enter the number of process that you wish to enter:\n");
	scanf("%d",&numberofprocess);

	printf("Enter the following details \nProcess name\nArrival time\nBurst time\n");
	for(int i =0;i<numberofprocess;i++)
	{
		scanf("%d",&name[i]);
		scanf("%d",&arrival[i]);
		scanf("%d",&burst[i]);
	}
	
	for(int i=0;i<numberofprocess-1;i++)
	{
		for(int j=0;j<numberofprocess-i-1;j++)
		{
			if(arrival[j]>arrival[j+1])
			{
				int temp = arrival[j];
				arrival[j] = arrival[j+1];
				arrival[j+1] = temp;

				temp = burst[j];
				burst[j] = burst[j+1];
				burst[j+1] = temp;

				temp = name[j];
				name[j] = name[j+1];
				name[j+1] = temp;
			}
		}
	}

	if(arrival[0] != 0)
	{
		time = time + arrival[0];
	}

	for(int j=0;j<numberofprocess;j++)
	{
		for(int i=0;i<numberofprocess;i++)
		{
			if(done[i] != 1)
			{
				
			}
		}
	}

	for(int i=0;i<numberofprocess;i++)
	{
		totalturnaround = totalturnaround + turnaround[i];
		totalwaiting = totalwaiting + waiting[i];
	}

	printf("\n\nAverage TurnAround Time is :\n%f",totalturnaround/numberofprocess);
	printf("\n\nAverage Waiting Time is :\n%f",totalwaiting/numberofprocess);
}