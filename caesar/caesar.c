#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    // check for correct number of arguments (argc(argument count)) need stdlib.h
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // add string.h for strlen - make sure key is non-neg integer
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // return a value (error) if the input is not a digit (isdigit from ctype.h instead of ascii table)
        if (!isdigit(argv[1][i]))
        {
            // error message if input is wrong - exit with status code 1
            printf("usage: .caesar key");
            return 1;
        }
    }

    // convert the key from string to integer (atoi (asciiToInteger)) take string of ascii char as input return as int
    int k = atoi(argv[1]);

    // get plaintext (inpu) from user
    string plaintext = get_string("plaintext: ");

    // encrypt plaintext using caesar cipher
    printf("ciphertext: ");

    // Loop through each character in the plaintext string. Start at first character (index 0) continue to end of string (index
    for (int j = 0; j < strlen(plaintext); j++)
    {

        // convert upper to lower skipping ascii non-letter variables (%c for character value in value)
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        // convert from lower to upp using ascii have to reduce to skip non letters
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        // if is not a letter - leave unchanged
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    // print new line
    printf("\n");
}