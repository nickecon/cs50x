#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_letters(string s);

int main(void)
{
    string text = get_string("Text: ");
    int counttt = 0;
    for (int k = 0; k<strlen(text); k++)
    {
        if(text[k] != ' ' || text[k] != '.')
        counttt++;
    }
    printf("total letters : %d", counttt);
    int let = counttt;
    printf("\n");
}