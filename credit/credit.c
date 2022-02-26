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
    int mod = 10;
    int tot = 0;
    for (int i = i; i < 11; i+=2) {
            int temp = n%mod;
            mod = mod * 10;
            int temp2 = n%mod;
            temp = (temp2 - temp)/temp;
            printf("d", tot);
            tot = tot + (temp*2);
            printf("d", tot);
    }
    else
    {
        printf("INVALID\n");
    }
}
