#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    int letters_sum = 0;
    int sentences = 0;
    string text = get_string("Text: ");

    int word_counter = 0;
    int letter_counter = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];

        if (letter == ' ')
        {
            word_counter++;
            continue;
        }

        if (letter == '.' || letter == '?' || letter == '!')
        {
            sentences++;

        }

        if (tolower(letter) <= 'z' && tolower(letter) >= 'a')
        {
            letter_counter++;
        }
    }

    word_counter++;
    letters_sum = letter_counter;


    float index = 0.0588 * ((float) letters_sum / (float) word_counter * 100.0) - 0.296 * ((float)sentences / (float)word_counter * 100.0) - 15.8;

    if (index > 16.0)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }

    return 0;
}
