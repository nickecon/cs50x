#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc==1 || argc>=4)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    if (argc==2)
    {
        return 1;
    }
    if (argc==3)
    {
        printf("ciphertext: %s\n", argv[0]);
        return 0;
    }
}

string only_digits()