#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool only_digits(string s);
//int isdigit(char c);
//make sure program was run w just one command line argument

//make sure every character in argv[1] is a digit

//convert avg[1] from a string to an int

//prompt user for plaintext

//for each character in the plaintext:

    //rotate the character if its a letter
int main(int argc, string argv[])
{
    if (argc>=4)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    if (argc==1)
    {
        return 1;
    }
    if (argc==2)
    {
        return 0;
    }
    if (argc==3)
    {
       // if
       // {
       //     (only_digits(argv[3]));
       // }
       // else
       // {
            printf("ciphertext: %s\n", argv[2]);
    }
        return 0;
    }


bool only_digits(string s);
