#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string l);
int count_words(string w);

int main(void)
{
    string l = get_string("Text: ");
    int letters = count_letters(l);
    int words = count_words(w);
    printf("%i letters\n", letters);
    printf("%i words\n", words);
}

int count_words(string w)
{
    int i = 0;
    for (int j = 0; j < strlen(w); j++)
    {
        if (w[j] = " ")
        {
            i++;
        }
    }
    return i;
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

