#include <stdio.h>
#include <stdlib.h>

int name[10],burst[10],arrival[10],complete[10],waiting[10],turnaround[10],priority[10],tempburst[10],done[10];
int numberofprocess,timesplice,time=0;
float averageturnaround,averagewaiting,totalturnaround = 0,totalwaiting = 0;

void fcfs()
{
	printf("Enter the number of process that you wish to enter\n");
	scanf("%d",&numberofprocess);

	for(int i = 0; i < numberofprocess; i++)
	{
		printf("Enter the number of process\n");
		scanf("%d",&name[i]);
		printf("Enter the arrival time of process[%d]\n",name[i]);
		scanf("%d",&arrival[i]);
		printf("Enter the burst time of process[%d]\n",name[i]);
		scanf("%d",&burst[i]);
	}

	for(int i = 0; i < numberofprocess; i++)
	{
		done[i] = 0;
	}

		for(int i = 0; i < numberofprocess - 1; i++)
	{
		for(int j = i; j < numberofprocess - i - 1; j++)
		{
			if(arrival[j] > arrival[j+1])
			{
				int temp = name[j];
				name[j] = name[j+1];
				name[j+1] = temp;

				temp = arrival[j];
				arrival[j] = arrival[j+1];
				arrival[j+1] = temp;
			}
		}
	}

	for(int i = 0; i < numberofprocess; i++)
	{
		if(arrival[i] <= time)
		{
			time = time + burst[i];
			complete[i] = time;
			turnaround[i] = complete[i] - arrival[i];
			waiting[i] = turnaround[i] - burst[i];
		}
		else
		{
			time = time + (arrival[i+1] - arrival[i]);
		}
	}

	for(int i = 0; i < numberofprocess; i++)
	{
		totalturnaround = totalturnaround + turnaround[i];
		totalwaiting = totalwaiting + waiting[i];
	}

	printf("\nNAME\tARRIVAL\tBURST TIME\tCOMLETION TIME\tTURNAROUND TIME\tWAITING TIME\n");
	for(int i = 0; i < numberofprocess; i++)
	{
		printf("%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",name[i],arrival[i],burst[i],complete[i],turnaround[i],waiting[i]);
	}

	averageturnaround = totalturnaround/numberofprocess;
	averagewaiting = totalwaiting/numberofprocess;

	printf("\nAverage TurnAround Time: %f\n",averageturnaround);
	printf("Average Waiting Time: %f\n",averagewaiting);
	
}

void sjf()
{
	printf("Enter the number of process that you wish to enter\n");
	scanf("%d",&numberofprocess);

	complete[-1] = 0;
	for(int i = 0; i < numberofprocess; i++)
	{
		printf("Enter the number of process\n");
		scanf("%d",&name[i]);
		printf("Enter the burst time of process[%d]\n",name[i]);
		scanf("%d",&burst[i]);
	}

	for(int i = 0; i < numberofprocess - 1; i++)
	{
		for(int j = i; j < numberofprocess - i - 1; j++)
		{
			if(burst[j] > burst[j+1])
			{
				int temp = name[j];
				name[j] = name[j+1];
				name[j+1] = temp;

				temp = burst[j];
				burst[j] = burst[j+1];
				burst[j+1] = temp;
			}
		}
	}

	for(int i = 0; i< numberofprocess; i++)
	{
		complete[i] = complete[i-1] + burst[i];
		turnaround[i] = complete[i];
		waiting[i] = turnaround[i] - burst[i];

		totalturnaround = totalturnaround + turnaround[i];
		totalwaiting = totalwaiting + waiting[i];
	}

	printf("\nNAME\tBURST TIME\tCOMLETION TIME\tTURNAROUND TIME\tWAITING TIME\n");
	for(int i = 0; i < numberofprocess; i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",name[i],burst[i],complete[i],turnaround[i],waiting[i]);
	}

	averageturnaround = totalturnaround/numberofprocess;
	averagewaiting = totalwaiting/numberofprocess;

	printf("\nAverage TurnAround Time: %f\n",averageturnaround);
	printf("Average Waiting Time: %f\n",averagewaiting);
}

void prioritys()
{
	printf("Enter the number of process that you wish to enter\n");
	scanf("%d",&numberofprocess);

	complete[-1] = 0;
	for(int i = 0; i < numberofprocess; i++)
	{
		printf("Enter the number of process\n");
		scanf("%d",&name[i]);
		printf("Enter the burst time of process[%d]\n",name[i]);
		scanf("%d",&burst[i]);
		printf("Enter the priority of process[%d]\n",name[i]);
		scanf("%d",&priority[i]);
	}

	for(int i = 0; i < numberofprocess - 1; i++)
	{
		for(int j = i; j < numberofprocess - i - 1; j++)
		{
			if(priority[j] > priority[j+1])
			{
				int temp = name[j];
				name[j] = name[j+1];
				name[j+1] = temp;

				temp = burst[j];
				burst[j] = burst[j+1];
				burst[j+1] = temp;

				temp = priority[j];
				priority[j] = priority[j+1];
				priority[j+1] = temp;
			}
		}
	}

	for(int i = 0; i< numberofprocess; i++)
	{
		complete[i] = complete[i-1] + burst[i];
		turnaround[i] = complete[i];
		waiting[i] = turnaround[i] - burst[i];

		totalturnaround = totalturnaround + turnaround[i];
		totalwaiting = totalwaiting + waiting[i];
	}

	printf("\nNAME\tBURST TIME\tCOMLETION TIME\tPRIORITY\tTURNAROUND TIME\tWAITING TIME\n");
	for(int i = 0; i < numberofprocess; i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",name[i],burst[i],complete[i],priority[i],turnaround[i],waiting[i]);
	}

	averageturnaround = totalturnaround/numberofprocess;
	averagewaiting = totalwaiting/numberofprocess;

	printf("\nAverage TurnAround Time: %f\n",averageturnaround);
	printf("Average Waiting Time: %f\n",averagewaiting);
}

void roundrobin()
{
	printf("Enter the number of process that you wish to enter\n");
	scanf("%d",&numberofprocess);

	for(int i = 0; i < numberofprocess; i++)
	{
		printf("Enter the number of process\n");
		scanf("%d",&name[i]);
		printf("Enter the burst time of process[%d]\n",name[i]);
		scanf("%d",&burst[i]);
	}

	printf("Enter the time splice\n");
	scanf("%d",&timesplice);

	for(int i = 0; i < numberofprocess; i++)
	{
		tempburst[i] = 0;
		done[i] = 0;
	}

	for(int k = 0; k < numberofprocess; k++)
	{
		for(int i = 0; i < numberofprocess; i++)
		{
			if(done[i] == 0)
			{
				if(tempburst[i] <= timesplice)
				{
					done[i] = 1;
					time = time + tempburst[i];
					complete[i] = time;

					turnaround[i] = complete[i];
					waiting[i] = turnaround[i] - burst[i];
				}

				else
				{
					time = time + timesplice;
					tempburst[i] = tempburst[i] - timesplice;
				}
			}
		}
	}

	for(int i = 0; i < numberofprocess; i++)
	{
		totalturnaround = totalturnaround + turnaround[i];
		totalwaiting = totalwaiting + waiting[i];
	}

	printf("\nNAME\tBURST TIME\tCOMLETION TIME\tTURNAROUND TIME\tWAITING TIME\n");
	for(int i = 0; i < numberofprocess; i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",name[i],burst[i],complete[i],turnaround[i],waiting[i]);
	}

	averageturnaround = totalturnaround/numberofprocess;
	averagewaiting = totalwaiting/numberofprocess;

	printf("\nAverage TurnAround Time: %f\n",averageturnaround);
	printf("Average Waiting Time: %f\n",averagewaiting);
}

void main()
{
	int choice;

	printf("\nEnter the Scheduling process that you wish to do\n");
	printf("1: First Come First Serve\n");
	printf("2: Shortest Job First\n");
	printf("3: Priority\n");
	printf("4: Round Robin\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			fcfs();
			break;

		case 2:
			sjf();
			break;

		case 3:
			prioritys();
			break;

		case 4:
			roundrobin();
			break;

		default:
			exit(0);
	}
}