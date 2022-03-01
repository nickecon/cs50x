#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int k);
//int isdigit(char c);
//make sure program was run w just one command line argument

//make sure every character in argv[1] is a digit

//convert avg[1] from a string to an int

//prompt user for plaintext

//for each character in the plaintext:

    //rotate the character if its a letter
int main(int argc, string argv[])
{
    if (argc>=3 || argc==1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else if (argc==2 && only_digits(argv[1]))
    {
        string s = get_string("plaintext:  ");
        int k = atoi(argv[1]);
        char c[strlen(s) +1];

        for (int i = 0, n = strlen(s); i < n; i++)
        {
            char cipher = rotate(s[i], k);
            printf("%c", cipher);
            //printf("%c", rotate(s[i]), k);
        }

        //(int i = 0, n = strlen(s); i < n; i++)
        //{
        //    printf("%c", s[i]);
        //}
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

char rotate(char c, int k)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = (c+k)%26;
        }
        else
        {
            c = (c+k)%26;
        }
    }
    else
    return c;
}