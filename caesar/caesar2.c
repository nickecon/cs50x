#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);
//int isdigit(char c);
//make sure program was run w just one command line argument

//make sure every character in argv[1] is a digit

//convert avg[1] from a string to an int

//prompt user for plaintext

//for each character in the plaintext:

    //rotate the character if its a letter
int main(int argc, string argv[])
{
int k = atoi(argv[1]);
    if (argc>=3 || argc==1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else if (argc==2 && only_digits(argv[1]))
    {
    string s = get_string("plaintext:  ");
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%c", s[i]);
        }
        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
        {
            if (isdigit(s[i]))
            {
                return true;
            }
            else
            return false;
        }
    return s;
}

char rotate(char c, int n)
{
    (c + k)%26
}

