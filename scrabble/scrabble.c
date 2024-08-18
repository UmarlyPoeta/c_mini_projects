#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int get_points(char character)
{
    int ascii_to_points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    if (((int) character > 96) && ((int) character < 122))
    {
        return ascii_to_points[(int) (character - 97)];
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int word1_points = 0;
    int word2_points = 0;

    for (int i = 0; i < strlen(word1); i++)
    {
        word1_points += get_points(tolower(word1[i]));
    }

    for (int i = 0; i < strlen(word2); i++)
    {
        word2_points += get_points(tolower(word2[i]));
    }

    if (word1_points > word2_points)
    {
        printf("Player 1 wins!\n");
    }
    else if (word1_points < word2_points)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}