#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // The image is a 2D array of pixels

    // loop through the rows
    for (int i = 0; i < height; i++)
    {
        // loop through the coloums
        for (int j = 0; j < width; j++)
        {
            // if pixel in [i][j] location of array is BLACK (000000)
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                //change it to Purple (FF00FF)
                image[i][j].rgbtRed = 0xFF;     // alot of red
                image[i][j].rgbtGreen = 0x00;   // no green
                image[i][j].rgbtBlue = 0xFF;    // alot of blue
            }
        }
    }
}
