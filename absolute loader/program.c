#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Main Function starts
void main()
{
    FILE *object;  // pointer to file stream
    char string[100],line[100];  // storing a string  of length 100 characters
    int i,j,loc;  // variables to loop over

    object = fopen("objectcode.txt","r"); // open a object code file named "objectcode.txt" in read-only mode

    fscanf(object,"%s",string); // reads data from the file into the string array

    // If first character in a line is 'H'
    if(string[0]=='H')
    {
        for(i=2; string[i] != '^'; i++)  //loop until a '^' character is not found 
        {
            line[i-2] = string[i];  // store the characters in the line array  
        }
        printf("The object code name is : %s\n",line);  // print the stored object code name
    }

    fscanf(object,"%s",string);  // scan the next line in the object code file into the string array

    // while the file is not empty
    while(!feof(object))
    {
        // if the first character in the string is 'T'
        if(string[0] == 'T')
        {
            // grab the characters after the 'T' character until '^' character is not found
            for(i=2;string[i] != '^'; i++)
            {
                line[i-2] = string[i];  //store the characters in line array
            }

            loc = atoi(line);  // convert the string to an integer

            i=12;  // start from the 12th position in the string array
            // while the end of the string is not reached
            while(string[i] != '\0')
            {
                if(string[i] != '^')
                {
                    printf("\n00%d      ",loc); // display the location in 00xy accordance
                    for(j=0; j<2; j++,i++)  // loop over two characters
                    {
                        printf("%c",string[i]);  // display two characters forming the object code
                    }
                    loc++;  // increment the location
                }
                else
                {
                    i++;  // increment the index
                }
            }
        }

        // if the first character of the string is 'E'
        if(string[0] == 'E')
        {
            for(i=2;i<8;i++) // grab the characters after 'E' till the 8th position
            {
                line[i-2] = string[i];  // store the data grabbed in the line
            }
            printf("\n\nThe ponter is pointed to  [%s]  to begin the execution\n\n",line); // print the starting location
        }

        fscanf(object,"%s",string);  // scan the next line into the string array
    }

    fclose(object);  // close the stream
}