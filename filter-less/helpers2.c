#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0));
            break;
            image[i][j].rgbtBlue = round(((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0));
            break;
            image[i][j].rgbtGreen = round(((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0));
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
            image[i][j].rgbtRed = sR;
            image[i][j].rgbtGreen = sG;
            image[i][j].rgbtBlue = sB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             if (image[0][0] || image[0][width-1]) || image[height-1][0] || image[height-1][width-1])
             {
                 image[i][j].rgbtBlue =
                 image[i][j].rgbt
             }
        }
    }
    if (image[0][0] || image[0][width-1]) || image[height-1][0] || image[height-1][width-1])
    image[0][0] = image[i-1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i+1][j-1] + image[i][j-1] + image[i-1][j-1] + image[i][j] / 4;
    if // surrounding is edge
    int blur = image[i-1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i+1][j-1] + image[i][j-1] + image[i-1][j-1] + image[i][j] / 6;
    if // surrounding is middle
    int blur = image[i-1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i+1][j-1] + image[i][j-1] + image[i-1][j-1] + image[i][j] / 9;
    RGBTRIPLE image[i][j] = RGBTRIPLE_COPY image[i][j];
        }
    return;
}

