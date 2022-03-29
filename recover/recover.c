#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //open memory card
    FILE *f = fopen(argv[1], "r");

    //start of JPEG -- 0xff 0xd8 0xff 0xe0-0xef
    buffer[0] == 0xff
    buffer[1] == 0xd8
    buffer[2] == 0xff
    (buffer[3] & 0xf0) == 0xe0

    //making a new JPEG
    sprintf(filename, "%03i.jpg", 1);
    FILE * img = fopen(filename, "w")

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