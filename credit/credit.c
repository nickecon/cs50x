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
        int mod = 10;
        int tot = 0;
        for (int i = 1; i < 11; i+=2) {
                int temp = n%mod;
                printf("temp = %d, mod = %d ---->", temp, mod);
                printf("total now (%d), mod(%d): %d -->  ", tot, mod, i);
                mod = mod * 10;
                int temp2 = n%mod;
                temp = (temp2 - temp)/temp;
                tot = tot + (temp*2);
                printf("total now(%d), mod(%d): %d\n", tot, mod, i);
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
