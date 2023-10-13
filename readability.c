#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get input
    string text = get_string("Text: ");

    // calculate letters words in text - loop to go through and check if IS letter an add++
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // if is letter, add letter - calc if IS letter (ascii table lower caser 65 - 90 upper 97 - 122 OR the ISALPHA function)
        if (isalpha(text[i]))
        {
            letters++;
        }

        // there's no way to count number of WORDS so you can only guess words based on number of spaces. A line has 1 more word
        // than space so set WORD up to 1 instead of zero to begin counting higher
        else if (text[i] == ' ')
        {
            words++;
        }

        // cant count sentences - need to use sense to count things sentences END in
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // then calculate two values: L, which represents the average number of letters per 100 words, and S, which represents the
    // average number of sentences per 100 words.
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // then calculate an index value using a formula that takes L and S into account. this index value represents the reading level
    // of the text.
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // Finally, output reading level of the text as a string. IF the index value is less than 1, the program outputs "Before
    // Grade1"... etc

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
