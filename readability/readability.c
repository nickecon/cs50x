#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);

int main(void)
{
string s = get_string("Text: ");
for (int i = 0, n = strlen(s); i < n; i++)
{
    int input = count_letters(s[i]);
    print("%i letters", input);
}
//printf("%s\n", s);
}

int count_letters(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            return 0
        }
        else
        {
            return 1
        }
    }
}