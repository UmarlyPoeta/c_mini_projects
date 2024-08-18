#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(string number)
{
    int sum = 0;
    int first_digit, second_digit;
    for (int i = strlen(number) -2; i >= 0; i -= 2)
        {
            int digit = number[i] - '0';
            first_digit = (2 * digit) % 10;
            second_digit = (2 * digit) / 10;
            sum += (first_digit + second_digit);

        }
    for (int i = strlen(number) - 1; i >= 0; i -= 2)
    {
        sum += (number[i] - '0');
    }
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int loop_condition = 0;
    string number = get_string("Number: ");
    
    if (strlen(number) == 15 && number[0] == '3' && (number[1] == '4' || number[1] == '7'))
    {
        if (check(number))
            printf("AMEX\n");
        else
            printf("INVALID\n");
        return 0;
    }
    if (strlen(number) == 16 && number[0] == '5' && (number[1] - '0') > 0 && (number[1] - '0') < 6)
    {
        if (check(number))
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
        return 0;
    }
    if ((strlen(number) == 13 || strlen(number) == 16) && number[0] == '4')
    {
        if (check(number))
            printf("VISA\n");
        else
            printf("INVALID\n");
        return 0;
    }
    printf("INVALID\n");
    return 0;
}