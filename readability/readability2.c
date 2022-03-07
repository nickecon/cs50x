#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);

int main(void)
{
    string s = get_string("Text: ");
    int l = count_letters(s);
    printf("%i", l);
    printf(" letters\n");
}

int count_letters(string s)
{
    int i = 0;
    for (int j = 0, n = strlen(s); j < n; j++)
    {
        while (isalpha(s[i]))
        {
            return i++;
        }
    }
    return i;
}