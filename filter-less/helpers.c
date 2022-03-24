#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sR = round((image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189));
            int sG = round((image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168));
            int sB = round((image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131));
            if (sR > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sR;
            }
            if (sG > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sG;
            }
            if (sB > 255)
            {
                image[i][j].rgbtBlue = 25;
            }
            else
            {
                image[i][j].rgbtBlue = sB;
            }
        }
    }
    return;
}

// Reflect image horizontally
// int tmp = a;
// a = b;
// b = tmp;
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE tmp;
            tmp = image[i][j];
            int x = width - 1 - j;
            image[i][j] = image[i][x];
            image[i][x] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *&copy[i][j].rgbtBlue = *&image[i][j].rgbtBlue;
            *&copy[i][j].rgbtRed = *&image[i][j].rgbtRed;
            *&copy[i][j].rgbtGreen = *&image[i][j].rgbtGreen;
        }
    }

    if (image[0][0] || image[0][width-1])
    int blur = image[i-1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i+1][j-1] + image[i][j-1] + image[i-1][j-1] + image[i][j] / 4;
    if // surrounding is edge
    int blur = image[i-1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i+1][j-1] + image[i][j-1] + image[i-1][j-1] + image[i][j] / 6;
    if // surrounding is middle
    int blur = image[i-1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i+1][j-1] + image[i][j-1] + image[i-1][j-1] + image[i][j] / 9;
    RGBTRIPLE image[i][j] = RGBTRIPLE_COPY image[i][j];
        }
    return;
}
