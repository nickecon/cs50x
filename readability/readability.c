#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string l);
int count_words(string w);

int main(void)
{
    string letters = get_string("Text: ");
    int l = count_letters(l);
    printf("%i letters\n", l);
}

int count_letters(string l)
{
    int i = 0;
    for (int j = 0; j < strlen(l); j++)
    {
        if(isalpha(l[j]))
        {
            i++;
        }
    }
    return i;
}

