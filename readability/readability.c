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
    for (int j = 0; j < strlen(s); j++)
    {
        if((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122))
        {
            i++;
        }
    }
    return i;
}
