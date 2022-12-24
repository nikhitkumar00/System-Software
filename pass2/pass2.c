#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char label[10], opcode[10], operand[10], op[10],sym[10];
    int loc,obj;

	FILE *fp1,*fp2,*fp3,*fp4;

    fp1 = fopen("intermediate.txt","r");
    fp2 = fopen("optab.txt","r");
    fp3 = fopen("symtab.txt","r");

    fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    
    if(strcmp(opcode,"START") == 0)
    {
        fscanf(fp1,"%d\t%s\t%s\t%s\n",&loc,label,opcode,operand);
        while(strcmp(opcode,"END") != 0)
        {
            while(!feof(fp2))
            {
                fscanf(fp2,"%s\t%d\n",op,&obj);
                if(strcmp(op,opcode) == 0)
                {
                    printf("%d",obj);
                    break;
                }
            }
            while(!feof(fp3))
            {
                fscanf(fp3,"%s\t%d\n",sym,&obj);
                if(strcmp(sym,label) == 0)
                {
                    printf("%d\n",obj);
                    break;
                }
            }
            fscanf(fp1,"%d\t%s\t%s\t%s\n",&loc,label,opcode,operand);

        }
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    else
    {
        printf("\nFaulted Intermediate File\n");
        exit(0);
    }
}