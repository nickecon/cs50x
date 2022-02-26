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
        printf("In Range\n");
    }
    int mod = 0;
    int tot = 0;
    for (int i = 1; int j = 11; i++2) {
        while (i <= j) {
            mod = pow(10, i)
            int temp = n%mod
            tot = tot + (temp*2)

        };
    }
    else
    {
        printf("INVALID\n");
    }
}
