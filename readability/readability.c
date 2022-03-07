#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s = get_string("Text: ");
    int l = count_letters(s);
    int w = count_words(s);
    int se = count_sentences(s);
    int index = 0.0588 * L - 0.296 * S - 15.8
    //0.0588 * L - 0.296 * S - 15.8

    //L = average # of letters per 100 words
    //L = letters/words * 100
    //S = average # of sentences per 100 words
    //S = 
    //printf("%i letters\n", letters);
    //printf("%i words\n", words);
    //printf("%i sentences\n", sentences);
}

int count_sentences(string s)
{
    int i = 0;
    for (int j = 0; j < strlen(s); j++)
    {
        if (s[j] == '.')
        {
            i++;
        }
    }
    return i;
}

int count_words(string s)
{
    int i = 1;
    for (int j = 0; j < strlen(s); j++)
    {
        if (s[j] == ' ')
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

