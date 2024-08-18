#include <cs50.h>
#include <stdio.h>

int main()
{
    int height = -2;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    for (int i = 1; i <= height; i++)
    {
        for (int space = 0; space < height - i; space++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}