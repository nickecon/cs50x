#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc==1)
    {
        return 1;
    }
    else
    {
        printf("ciphertext: %s\n", argv[0]);
        return 0;
    }
}