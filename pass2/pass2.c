#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
      char label[10], mnemonic[10], operand[10],location[10], totallength[10];
      char opcode[10], opcodeaddress[10], symbol[10], symboladdress[10];
      int start;

      FILE *intermediate, *optab, *symtab, *object, *length;

      intermediate      =     fopen("intermediate.txt","r");
      optab             =     fopen("optab.txt","r");
      symtab            =     fopen("symtab.txt","r");
      object            =     fopen("object.txt","w");
      length            =     fopen("length.txt","r");

      fscanf(intermediate,"%s%s%s%s",location, label, mnemonic, operand);

      if(strcmp(mnemonic,"START") == 0)
      {
            start = atoi(location);
            fscanf(length,"%s",totallength);
      }
      else
      {
            printf("\n\nNO START\n\n");
            exit(0);
      }

      fprintf(object,"H^%s^%s^%s\nT^%s",label, location, totallength,location);

      fscanf(intermediate,"%s%s%s%s",location, label, mnemonic, operand);

      while (strcmp(mnemonic,"END") != 0)
      {
            rewind(optab);
            while(fscanf(optab,"%s%s",opcode,opcodeaddress) != EOF)
            {
                  if(strcmp(opcode,mnemonic) == 0)
                  {
                        fprintf(object,"^%s",opcodeaddress);

                        rewind(symtab);
                        while(fscanf(symtab,"%s%s",symbol,symboladdress) != EOF)
                        {
                              if(strcmp(symbol,operand) == 0)
                              {
                                    fprintf(object,"%s",symboladdress);
                              }
                        }
                  }
                  else if(strcmp("WORD",mnemonic) == 0 || strcmp("BYTE",mnemonic) == 0)
                  {
                        fprintf(object,"^0000%s",operand);
                  }
                  else if(strcmp("RESW",mnemonic) == 0 || strcmp("RESB",mnemonic) == 0)
                  {
                        break;
                  }                  
            }

            fscanf(intermediate,"%s%s%s%s",location, label, mnemonic, operand);
      }

      fprintf(object,"\nE^%d",start);

      fclose(intermediate);
      fclose(optab);
      fclose(symtab);
      fclose(length);
      fclose(object);
}
