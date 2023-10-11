#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 // from notes

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        // Print error message if the program is not given the correct number of arguments
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the forensic image file specified in the command-line arguments (NOTES)
    char *file = argv[1];
    FILE *raw_file = fopen(file, "r");
    if (raw_file == NULL)
    {
        // Print an error message to standard error if the forensic image file cannot be opened (NOTES)
        printf("Could not open %s.\n", file);
        return 1;
    }

    // Initialize variables
    bool found_jpg = false;     // Flag to keep track of whether a JPEG has been found
    int jpg_count = 0;          // Counter for the number of JPEGs found
    uint8_t buffer[BLOCK_SIZE]; // Buffer to store a block of data from the forensic image (NOTES)
    char jpg_name[8];           // Array to store the filename of the current JPEG
    FILE *outptr = NULL;        // Pointer to the current JPEG file

    // Read the forensic image file block by block (NOTES)
    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        // Check if this block marks the start of a new JPEG (NOTES)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous JPEG file, if one was open
            if (found_jpg)
            {
                fclose(outptr);
            }
            else
            {
                found_jpg = true;
            }
            // Open a new JPEG file
            sprintf(jpg_name, "%03d.jpg",
                    jpg_count); // Generate the filename for the new JPEG image file based on the jpg_count variable (NOTES)
            outptr = fopen(jpg_name, "w"); // Open a new JPEG image file with the generated filename
            if (outptr == NULL)
            {
                fclose(raw_file);
                printf("Could not create %s. \n", jpg_name); // Print an error if the new JPEG Image file cannot be created
                return 3;
            }
            jpg_count++; // Increment the jpg_count variable
        }
        // Write the current block to the current JPEG file, if one is open
        if (found_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }

    // Close the forensic image file and the last JPEG file, if one was open
    fclose(raw_file);
    if (found_jpg)
    {
        fclose(outptr);
    }
    // Exit the program with a status code of 0 to indicate process
    return 0;
}