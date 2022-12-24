#include <stdio.h>
#include <stdlib.h>

void input(char a)
{
	
}

void main()
{
	char readfile[100], writefile[100], input[100];
	FILE *f1;

	printf("\nEnter the name of the file that is needed to be read from:\n");
	scanf("%s",readfile);

	f1 = fopen(readfile,"r");
	if(f1 == NULL)
	{
		printf("File not open\n");
		exit(0);
	}
	
	while(f1 != EOF)
	{
		fgetc(input);
		look(input);
	}

	fclose(f1);
}