#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //for each row
    for (int i = 0; i < n; i++)
    {
        //for each column
        for (int k = n - 1; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //print new line
        printf("\n");
    }
}