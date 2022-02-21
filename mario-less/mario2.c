#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 8);

    //for each row
    for (int i = 0; i < n; i++)
    {
        //for each column
        for (int k = 0; k > i; k--)
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }
        //print new line
        printf("\n");
    }
}