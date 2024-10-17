#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // If there are less than 4 arguments, inform the user that they must supply a source file and two destination files.
    if (argc < 4) 
    {
        printf("You must supply a source file and two destination files.\n");
        exit(1);
    }

    // Create a file pointer that opens the source file and sets the mode of the file to read.
    FILE *inRead = fopen(argv[1], "r");

    // Create two file pointers that open the destination files and set the mode of the files to write.
    FILE *inWrite1 = fopen(argv[2], "w");
    FILE *inWrite2 = fopen(argv[3], "w");

    // Create counters that count how many lines are written to each destination file.
    int counter1 = 0;
    int counter2 = 0;

    // Delcare a string that holds a line in the file.
    char line[255];

    // While the current line from the the file being read is not past the end of the file...
    while (fgets(line, 255, inRead) != NULL)
    {
        // If the length of the line is less than 20...
        if (strlen(line) < 20)
        {
            // Change every lower case letter to upper case.
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = toupper(line[i]);
            }

            // Write the line to the first destination file.
            fprintf(inWrite1, "%s\n", line);

            // Increase the counter for the first destination file by 1. 
            counter1++;
        }

        // Otherwise...
        else
        {
            // Change every upper case letter to lower case.
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = tolower(line[i]);
            }

            // Write the line to the second destination file.
            fprintf(inWrite2, "%s\n", line);

            // Increase the counter for the second destination file by 1.
            counter2++;
        }
    }

    // Close the source and destination files using their file pointers.
    fclose(inRead);
    fclose(inWrite1);
    fclose(inWrite2);

    // Display the number of lines written to each destination file using their corresponding counters.
    printf("%d lines written to %s\n", counter1, argv[2]);
    printf("%d lines written to %s\n", counter2, argv[3]);
}