#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);
int count_words(string s);

int main(void)
{
    string s = get_string("Text: ");
    int letters = count_letters(s);
    int words = count_words(s);
    printf("%i letters\n", letters);
    printf("%i words\n", words);
}

int count_words(string s)
{
    int i = 0;
    for (int j = 0; j < strlen(s); j++)
    {
        if (s[j] = " ")
        {
            i++;
        }
    }
    return i;
}

int count_letters(string s)
{
    int i = 0;
    for (int j = 0; j < strlen(s); j++)
    {
        if(isalpha(s[j]))
        {
            i++;
        }
    }
    return i;
}

