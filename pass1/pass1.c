#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
      char  label[10], mnemonic[10], operand[10];
      char  symbol[10], symboladdress[10], opcode[10], opaddress[10];
      int   start, locctr, flag, totallength;

      FILE *source, *optab, *symtab, *intermediate, *length;

      source            =fopen("source.txt","r");
      optab             =fopen("optab.txt","r");
      symtab            =fopen("symtab.txt","w");
      intermediate      =fopen("intermediate.txt","w");
      length            =fopen("length.txt","w");

      fscanf(source,"%s%s%s", label, mnemonic, operand);

      if(strcmp(mnemonic, "START") == 0)
      {
            start   = atoi(operand);
            printf("\nThe starting Address is: %d\n",start);
            locctr  = start;
            fprintf(intermediate,"%d\t%s\t%s\t%s\n", locctr, label, mnemonic, operand);
      }

      else
      {
            start  = 0;
            printf("\nThe starting Address is: %d\n",start);
            locctr = start;
      }

      fscanf(source,"%s%s%s", label, mnemonic, operand);
      while(strcmp(mnemonic, "END") != 0)
      {
            fprintf(intermediate,"%d\t%s\t%s\t%s\n", locctr, label, mnemonic, operand);

            if(strcmp(label,"-") != 0)
            {
                  flag = 0;
                  rewind(symtab);
                  while(fscanf(symtab,"%s%s",symbol,symboladdress) != EOF)
                  {
                        if(strcmp(symbol, label) == 0)
                        {
                              flag = 1;
                        }
                  }
                  rewind(symtab);
                  
                  if(flag == 0)
                  {
                        fprintf(symtab,"%s\t%d\n",label,locctr);
                  }
                  else
                  {
                        printf("\n\nERROR OCCURED\nDUPLICATE SYMBOL IN SYMTAB\n\n");
                        exit(0);
                  }
            }

            flag = 0;
            rewind(optab);
            while(fscanf(optab,"%s%s",opcode,opaddress) != EOF)
            {
                  if(strcmp(opcode, mnemonic) == 0)
                  {
                        locctr += 3;
                        flag = 1;
                        break;
                  }

                  else if(strcmp(mnemonic, "WORD") == 0)
                  {
                        locctr += 3;
                        flag = 1;
                        break;
                  }

                  else if(strcmp(mnemonic, "RESW") == 0)
                  {
                        locctr = locctr + (3 * atoi(operand));
                        flag = 1;
                        break;
                  }

                  else if(strcmp(mnemonic, "RESB") == 0)
                  {
                        locctr += atoi(operand);
                        flag = 1;
                        break;
                  }

                  else if(strcmp(mnemonic, "BYTE") == 0)
                  {
                        locctr += strlen(operand);
                        flag = 1;
                        break;
                  }
            }
            if(flag == 0)
            {
                  printf("\n\nERROR OCCURED\nOPCODE NOT FOUND\n\n");
                  exit(0);
            }

            fscanf(source,"%s%s%s", label, mnemonic, operand);
      }
      fprintf(intermediate,"%d\t%s\t%s\t%s\n", locctr, label, mnemonic, operand);

      totallength = locctr - start;
      fprintf(length,"%d",totallength);

      fclose(source);
      fclose(intermediate);
      fclose(optab);
      fclose(symtab);
      fclose(length);
}
