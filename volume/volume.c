// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header - define a constant HEADER_SIZE to store the number of bytes in a .wav file's header; 44 bytes.
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments - check that program called with exactly three command line arguments: input file name, output
    // file name, and scalling factor for the audio. Else error
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor - attempt to open input file specified in the command line arguments for reading.
    // Else error
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // - Attempt to open output file specified in the command line arguments for writing. Else error
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Converts scaling factor argument from a string to float using the atof() function.
    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];

    // Read Data (Header) from file
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);

    // Write data (Header) to a file
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t sample;

    // Read data (audio & scaling) from file
    // Write data (update audio) to file
    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        sample *= factor;
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
