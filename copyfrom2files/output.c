//Given 2 university information files 
//studentname.txt and registernumber.txt that contains 
//student names and register number respectively
//write a c program to create a new file called output.txt
//and copy the contents of files 
//studentname.txt and registernumber.txt into the output file

#include <stdio.h>
#include <stdlib.h>

void main()
{
	char readfile[100], writefile[100], in[100], out[100];
	FILE *f1, *f2, *f3;

	f1 = fopen("studentname.txt","r");
	if(f1 == NULL)
	{
		printf("File not open\n");
		exit(0);
	}

	f2 = fopen("registernumber.txt","r");
	if(f2 == NULL)
	{
		printf("File not open\n");
		exit(0);
	}
	
	f3 = fopen("output.txt","w");

	fscanf(f1,"%s",in);
	fscanf(f2,"%s",out);
	while(!feof(f1))
	{
		fprintf(f3,"%s - [%s]\n",in,out);
		fscanf(f1,"%s",in);
		fscanf(f2,"%s",out);
	}
	fprintf(f3,"%s - ",in);
	fprintf(f3,"[%s]\n",out);

	fclose(f1);
	fclose(f2);
	fclose(f3);
}