#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s = get_string("Text: ");
    int l = count_letters(s);
    int w = count_words(s);
    int se = count_sentences(s);
    float L = ((float)l / (float)w) * 100;
    float S = ((float)se / (float)w) * 100;
    int bindex = round(0.0588 * L - 0.296 * S - 15.8);
    int index = round(bindex);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    //0.0588 * L - 0.296 * S - 15.8

    //L = average # of letters per 100 words
    //L = letters/words * 100
    //S = average # of sentences per 100 words
    //S = sentences/words *100
    //printf("%i letters\n", letters);
    //printf("%i words\n", words);
    //printf("%i sentences\n", sentences);
}

int count_sentences(string s)
{
    int i = 0;
    for (int j = 0; j < strlen(s); j++)
    {
        if (s[j] == '.' || s[j] == '!' || s[j] == '?')
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
        if (isalpha(s[j]))
        {
            i++;
        }
    }
    return i;
}

