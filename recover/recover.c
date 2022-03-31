#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //open memory card
    FILE *input = fopen(argv[1], "r");

    //check if valid
    if (input == NULL)
    {
        printf("Unable to open file\n");
        return 2;
    }

    //create buffer
    BYTE arr[512];

    //create filename
    char* filename = malloc(3 * sizeof(int));

    //create jpeg counter
    int count = 0;

    //read file
    while (fread(arr, 1, 512, input) == 512)
    {
        //check for jpeg header
        if (arr[0] == 0xff && arr[1] == 0xd8 && arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {
            //create new jpeg
            sprintf(filename, "%03i.jpg", count);
            FILE *img = fopen(filename, "w");
            fwrite(arr, 1, 512, img);
            fclose(img);
            count++;
        }
        //continue
        else if (count > 0)
        {
            FILE *img = fopen(filename, "a");
            fwrite(arr, 1, 512, img);
            fclose(img);
        }
    }
    return 0;
    fclose(input);
    free(arr);
}