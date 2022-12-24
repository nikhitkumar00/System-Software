#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char label[10], opcode[10], operand[10];
	int start,length,locctr;
	char code[10], mnemonic[10];

	FILE *fp1,*fp2,*fp3,*fp4,*fp5;

	fp1 = fopen("input.txt","r");
	fp2 = fopen("optab.txt","r");

	fp3 = fopen("intermediate.txt","w");
	fp4 = fopen("symtab.txt","w");
	fp5 = fopen("length.txt","w");

	fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

	if(strcmp(opcode,"START") == 0)
	{
		start = atoi(operand);
		locctr = start;

		fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
		fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	}
	else
	{
		locctr = 0;
	}

	while(strcmp(opcode,"END") != 0)
	{
		fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

		if(strcmp(label,"-") != 0)
		{
			fprintf(fp4,"%s\t%d\n",label,locctr);
		}

		fscanf(fp2,"%s\t%d",code,mnemonic);

		while(strcmp(code,"END") != 0)
		{
			if(strcmp(opcode,code) == 0)
			{
				locctr = locctr + 3;
				break;
			}
			fscanf(fp2,"%s\t%d",code,mnemonic);
		}

		if(strcmp(opcode,"WORD") == 0)
		{
			locctr = locctr + 3;
		}
		else if(strcmp(opcode,"RESW") == 0)
		{
			locctr = locctr + (3 * (atoi(operand)));
		}
		else if(strcmp(opcode,"BYTE") == 0)
		{
			locctr = locctr + 1;
		}
		else if(strcmp(opcode,"RESB") == 0)
		{
			locctr = locctr + atoi(operand);
		}
		fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	}
	fprintf(fp3,"%d\t%s\t%s\t%s",locctr,label,opcode,operand);

	length = locctr - start;
	fprintf(fp5,"The length of the file is %d",length);

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}