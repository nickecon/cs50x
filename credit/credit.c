#include <cs50.h>
#include <stdio.h>



int main(void)
{
    // ask for number
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    if (n > 3399999999999 && n < 56000000000000000)
    {
        printf("Looks good\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
