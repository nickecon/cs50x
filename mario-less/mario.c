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
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        //prints gap in middle
        printf("  ");
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }
        //print new line
        printf("\n");
    }
}