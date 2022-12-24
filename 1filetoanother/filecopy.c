//Write a program in c to copy one file to another file

#include <stdio.h>
#include <stdlib.h>

void main()
{
	char readfile[100], writefile[100], input[100];
	FILE *f1, *f2;

	printf("\nEnter the name of the file that is needed to be read from:\n");
	scanf("%s",readfile);

	f1 = fopen(readfile,"r");
	if(f1 == NULL)
	{
		printf("File not open\n");
		exit(0);
	}
	
	printf("Enter the name of the file that is to be written into:\n");
	scanf("%s",writefile);
	
	f2 = fopen(writefile,"w");
	if(f2 == NULL)
	{
		printf("File not open\n");
		exit(0);
	}

	fscanf(f1,"%s",input);
	printf("%s",input);
	while(!feof(f1))
	{
		fprintf(f2,"%s",input);
		fscanf(f1,"%s",input);
		printf("%s",input);
	}

	fclose(f1);
	fclose(f2);
}