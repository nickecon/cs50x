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
    FILE *file = fopen(argv[1], "r");

    //check if valid
    if (file != NULL)
    {
        printf("Unable to open file\n");
        return 2;
    }

    //create buffer
    BYTE arr[512];

    //create jpeg counter
    int count = 0;

    FILE *jpeg = NULL;

    //read file
    while (fread(arr, 1, 512, file) == 512)
    {
        if (arr[0] == 0xff && arr[1] == 0xd8 && arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {
            if()
            int njpg[512];
            sprintf(njpg, "%03i.jpg", 1);
            FILE *img = fopen(njpg, "w");
            fwrite(njpg, 1, 512, img)
        }
    }

//1) Search for header
//    a) Header found - close output file if it exists
//   b) Generate new filename
//   c) Open new file
//   d) Write to file
//2) Header not found - If output file is open, write to file.

    //start of JPEG -- 0xff 0xd8 0xff 0xe0-0xef
    //arr[0] == 0xff;
    //arr[1] == 0xd8;
    //arr[2] == 0xff;
    //(arr[3] & 0xf0) == 0xe0;

    //making a new JPEG
    //sprintf(filename, "%03i.jpg", 1);
    //FILE * img = fopen(filename, "w");



    //fread(data, size, number, inptr);
    //data: pointer to where to store data you're reading
    //size: size of each element to read
    //number: number of elements to read
    //inptr: FILE * to read from

    //fwrite(date, size, number, outptr);
    //data: pointer to bytes that will be written to file
    //size: size of each element to write
    //number: number of elements to wrtie
    //outptr: FILE * to write to
    //Returns number of items of size size were read
}

//Open memory card
//Repeat until end of card:
//  Read 512 bytes into a buffer - allocate room into memory
//  If start of new JPEG - read those 512 bytes that were allocated and see if start of new JPEG
//      If first JPEG 001.jpg - start writing first file
//
//      Else - close to open another
//  Else
//      If already found JPEG - keep writing another 512 bytes
//Close any remaining files