#include "helpers.h"
#include <math.h>

// Convert image to grayscale // Get averages of RGB values and set all 3 to average - Get averages then SET averages.
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (int) ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 + 0.5);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}

// Convert image to sepia // Get original values of RGB - Set values to 'sepia' version of original pixel values (from notes)
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Set the values of the images to the sepia values (from notes)
            image[i][j].rgbtRed =
                fmin(255, (int) (0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue + 0.5)); // convert red
            image[i][j].rgbtGreen =
                fmin(255, (int) (0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue + 0.5)); // convert green
            image[i][j].rgbtBlue =
                fmin(255, (int) (0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue + 0.5)); // convert blue
        }
    }
}

// Reflect image horizontally - SWAP values of the pixels on opposite sides of the VERTICAL CENTER of the image
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap the values of the pixels on opposite sides of image at vertical center
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j]; // Swaps pixels
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image - itterate over EACH pixel - vars to store rgb vals and counter in neighboring pixels itterating in 3x3 grid -
// calculate coordinates of neighboring pixels, skip if 00B, add RGB of neighboring Pixels to total RGB values, increment counter
// for neighboring pixels, set RGB vals of current pixel in temp array to average rgb of neighboring pixels, copy blurred pixels
// from temp array to original
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
            }

            temp[i][j].rgbtRed = round(totalRed / counter);
            temp[i][j].rgbtGreen = round(totalGreen / counter);
            temp[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
