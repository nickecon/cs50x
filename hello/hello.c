#include <stdio.h>
#include <cs50.h>

// Program asks user for name then produces greeting w/ name

int main(void)
{
    string name = get_string("What is your name?\n");

    printf("hello, %s\n", name);
}