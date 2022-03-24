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
        for (int j = 0; j < width / 2; j++)
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
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            * &copy[i][j].rgbtBlue = * &image[i][j].rgbtBlue;
            * &copy[i][j].rgbtGreen = * &image[i][j].rgbtGreen;
            * &copy[i][j].rgbtRed = * &image[i][j].rgbtRed;
        }
    }

//top corner
    image[0][0].rgbtBlue = round((copy[0][0].rgbtBlue + copy[0][1].rgbtBlue + copy[1][0].rgbtBlue + copy[1][1].rgbtBlue) / 4.0);
    image[0][0].rgbtGreen = round((copy[0][0].rgbtGreen + copy[0][1].rgbtGreen + copy[1][0].rgbtGreen + copy[1][1].rgbtGreen) / 4.0);
    image[0][0].rgbtRed = round((copy[0][0].rgbtRed + copy[0][1].rgbtRed + copy[1][0].rgbtRed + copy[1][1].rgbtRed) / 4.0);

//top right corner
    image[0][width - 1].rgbtBlue = round((copy[0][width - 1].rgbtBlue + copy[0][width - 2].rgbtBlue + copy[1][width - 1].rgbtBlue +
     copy[1][width - 2].rgbtBlue) / 4.0);
    image[0][width - 1].rgbtGreen = round((copy[0][width - 1].rgbtGreen + copy[0][width - 2].rgbtGreen + copy[1][width - 1].rgbtGreen +
     copy[1][width - 2].rgbtGreen) / 4.0);
    image[0][width - 1].rgbtRed = round((copy[0][width - 1].rgbtRed + copy[0][width - 2].rgbtRed + copy[1][width - 1].rgbtRed +
     copy[1][width - 2].rgbtRed) / 4.0);

//bottom left corner
    image[height - 1][0].rgbtBlue = round((copy[height - 1][0].rgbtBlue + copy[height - 1][1].rgbtBlue + copy[height - 2][0].rgbtBlue +
     copy[height - 2][1].rgbtBlue) / 4.0);
    image[height - 1][0].rgbtGreen = round((copy[height - 1][0].rgbtGreen + copy[height - 1][1].rgbtGreen + copy[height - 2][0].rgbtGreen +
     copy[height - 2][1].rgbtGreen) / 4.0);
    image[height - 1][0].rgbtRed = round((copy[height - 1][0].rgbtRed + copy[height - 1][1].rgbtRed + copy[height - 2][0].rgbtRed +
     copy[height - 2][1].rgbtRed) / 4.0);

//bottom right corner
    image[height - 1][width - 1].rgbtBlue = round((copy[height - 1][width - 1].rgbtBlue + copy[height - 1][width - 2].rgbtBlue + copy[height - 2][width - 1].rgbtBlue + copy[height - 2][width - 2].rgbtBlue) / 4.0);
    image[height - 1][width - 1].rgbtGreen = round((copy[height - 1][width - 1].rgbtGreen + copy[height - 1][width - 2].rgbtGreen + copy[height - 2][width - 1].rgbtGreen + copy[height - 2][width - 2].rgbtGreen) / 4.0);
    image[height - 1][width - 1].rgbtRed = round((copy[height - 1][width - 1].rgbtRed + copy[height - 1][width - 2].rgbtRed + copy[height - 2][width - 1].rgbtRed + copy[height - 2][width - 2].rgbtRed) / 4.0);

    for (int k = 1; k < height - 1; k++)
    {
        for (int l = 1; l < width - 1; l++)
        {
            //blurring the middle pixels
            image[k][l].rgbtBlue = round((copy[k - 1][l - 1].rgbtBlue + copy[k - 1][l].rgbtBlue + copy[k - 1][l + 1].rgbtBlue + copy[k][l - 1].rgbtBlue + copy[k][l].rgbtBlue + copy[k][l + 1].rgbtBlue + copy[k + 1][l - 1].rgbtBlue + copy[k + 1][l].rgbtBlue + copy[k + 1][l + 1].rgbtBlue) / 9.0);
            image[k][l].rgbtGreen = round((copy[k - 1][l - 1].rgbtGreen + copy[k - 1][l].rgbtGreen + copy[k - 1][l + 1].rgbtGreen + copy[k][l - 1].rgbtGreen + copy[k][l].rgbtGreen + copy[k][l + 1].rgbtGreen + copy[k + 1][l - 1].rgbtGreen + copy[k + 1][l].rgbtGreen + copy[k + 1][l + 1].rgbtGreen) / 9.0);
            image[k][l].rgbtRed = round((copy[k - 1][l - 1].rgbtRed + copy[k - 1][l].rgbtRed + copy[k - 1][l + 1].rgbtRed + copy[k][l - 1].rgbtRed + copy[k][l].rgbtRed + copy[k][l + 1].rgbtRed + copy[k + 1][l - 1].rgbtRed + copy[k + 1][l].rgbtRed + copy[k + 1][l + 1].rgbtRed) / 9.0);

            //top edge
            image[0][l].rgbtBlue = round((copy[0][l - 1].rgbtBlue + copy[0][l].rgbtBlue + copy[0][l + 1].rgbtBlue + copy[1][l - 1].rgbtBlue + copy[1][l].rgbtBlue + copy[1][l + 1].rgbtBlue) / 6.0);
            image[0][l].rgbtGreen = round((copy[0][l - 1].rgbtGreen + copy[0][l].rgbtGreen + copy[0][l + 1].rgbtGreen + copy[1][l - 1].rgbtGreen + copy[1][l].rgbtGreen + copy[1][l + 1].rgbtGreen) / 6.0);
            image[0][l].rgbtRed = round((copy[0][l - 1].rgbtRed + copy[0][l].rgbtRed + copy[0][l + 1].rgbtRed + copy[1][l - 1].rgbtRed + copy[1][l].rgbtRed + copy[1][l + 1].rgbtRed) / 6.0);

            //bottom edge
            image[height - 1][l].rgbtBlue = round((copy[height - 2][l - 1].rgbtBlue + copy[height - 2][l].rgbtBlue + copy[height - 2][l + 1].rgbtBlue + copy[height - 1][l - 1].rgbtBlue + copy[height - 1][l].rgbtBlue + copy[height - 1][l + 1].rgbtBlue) / 6.0);
            image[height - 1][l].rgbtGreen = round((copy[height - 2][l - 1].rgbtGreen + copy[height - 2][l].rgbtGreen + copy[height - 2][l + 1].rgbtGreen + copy[height - 1][l - 1].rgbtGreen + copy[height - 1][l].rgbtGreen + copy[height - 1][l + 1].rgbtGreen) / 6.0);
            image[height - 1][l].rgbtRed = round((copy[height - 2][l - 1].rgbtRed + copy[height - 2][l].rgbtRed + copy[height - 2][l + 1].rgbtRed + copy[height - 1][l - 1].rgbtRed + copy[height - 1][l].rgbtRed + copy[height - 1][l + 1].rgbtRed) / 6.0);

            //left edge
            image[k][0].rgbtBlue = round((copy[k - 1][0].rgbtBlue + copy[k - 1][1].rgbtBlue + copy[k][0].rgbtBlue + copy[k][1].rgbtBlue + copy[k + 1][0].rgbtBlue + copy[k + 1][1].rgbtBlue) / 6.0);
            image[k][0].rgbtGreen = round((copy[k - 1][0].rgbtGreen + copy[k - 1][1].rgbtGreen + copy[k][0].rgbtGreen + copy[k][1].rgbtGreen + copy[k + 1][0].rgbtGreen + copy[k + 1][1].rgbtGreen) / 6.0);
            image[k][0].rgbtRed = round((copy[k - 1][0].rgbtRed + copy[k - 1][1].rgbtRed + copy[k][0].rgbtRed + copy[k][1].rgbtRed + copy[k + 1][0].rgbtRed + copy[k + 1][1].rgbtRed) / 6.0);

            //right edge
            image[k][width - 1].rgbtBlue = round((copy[k - 1][width - 2].rgbtBlue + copy[k - 1][width - 1].rgbtBlue + copy[k][width - 2].rgbtBlue + copy[k][width - 1].rgbtBlue + copy[k + 1][width - 2].rgbtBlue + copy[k + 1][width - 1].rgbtBlue) / 6.0);
            image[k][width - 1].rgbtGreen = round((copy[k - 1][width - 2].rgbtGreen + copy[k - 1][width - 1].rgbtGreen + copy[k][width - 2].rgbtGreen + copy[k][width - 1].rgbtGreen + copy[k + 1][width - 2].rgbtGreen + copy[k + 1][width - 1].rgbtGreen) / 6.0);
            image[k][width - 1].rgbtRed = round((copy[k - 1][width - 2].rgbtRed + copy[k - 1][width - 1].rgbtRed + copy[k][width - 2].rgbtRed + copy[k][width - 1].rgbtRed + copy[k + 1][width - 2].rgbtRed + copy[k + 1][width - 1].rgbtRed) / 6.0);
        }
    }
    return;
}
