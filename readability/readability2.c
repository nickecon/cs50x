#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);

int main(void)
{
int l = 0; // letter counter
string s = get_string("Text: ");
for (int i = 0; i < strlen(s); i++)
{
    int input = count_letters(s);
    printf("%i", input);
}
printf(" letters\n");
}

int count_letters(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            return count++;
        }
        else
    }
    return count;
}