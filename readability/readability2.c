#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);

int main(void)
{
string s = get_string("Text: ");
int input = count_letters(s);
printf("%i", input);
printf(" letters\n");
//printf("%s\n", s);
}

int count_letters(string s)
{
    int count = 0;
    while (s[i] !=
    {
        if (isalpha(s[i]))
        {
            return count++;
        }
    }
    return count;
}