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
    for (int i = i; int j = 11; i+=2) {
        while (i <= j) {
            mod = pow(10, i)
            int temp = n%mod
            int temp2 = n%(mod + 1)
            temp = (temp2 - temp)/temp
            printf("d", tot)
            tot = tot + (temp*2)
            printf("d", tot)
        };
    }
    else
    {
        printf("INVALID\n");
    }
}
