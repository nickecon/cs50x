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
        printf("#");
        //for each column
        for (int j = i+1; j < n; j++)
            printf(" ");
        //print new line
        printf("\n");
    }
}