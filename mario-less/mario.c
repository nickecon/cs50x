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

    // for each row
    for (int i = 0; i < n; i++)
    {
        //for each column
        for (int j = 0; j< n; j++)
        {
            //print
            printf("#");
        }

        //move to next row
        printf("\n");
    }
}