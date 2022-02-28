#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc==1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc==2)
    {
        printf("ciphertext: %s\n", argv[0]);
        return 0;
    }
}