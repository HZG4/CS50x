#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // take average of rgbt values of Red, Green and Blue in [i][j] pixel
            int rgbGray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);

            // set rgbt values of Red, Green and Blue in [i][j] pixel to the average
            image[i][j].rgbtRed = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtBlue = rgbGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // sepiaRed = (0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue)
            sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));

            // sepiaGreen = (0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue)
            sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));

            // sepiaBlue = (0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue)
            sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            // if the result of the formula is a number greater than 255, then the rgbt values should be capped at 255.
            image[i][j].rgbtRed = fmin(sepiaRed, 255);
            image[i][j].rgbtGreen = fmin(sepiaGreen, 255);
            image[i][j].rgbtBlue = fmin(sepiaBlue, 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    //width of half image.
    int halfimg = width / 2;

    // loop through rows
    for(int i = 0; i < height; i++)
    {
        //loop through colums till halfway in image
        for(int j = 0; j < halfimg; j++)
        {
            // storing [i][j] in temp
            temp = image[i][j];

            //replacing [i][j] with [i][width-j-1] and vice versa.
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temp array to keep rgbt values of orignal pixels while we modify the pixels.
    RGBTRIPLE temp[height][width];

    // save image[i][j] values in temp[i][j].
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // blur box algorithm in code
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //  defining variables to sum total RGBs from grid of pixels.
            int totalRed   = 0;
            int totalGreen = 0;
            int totalBlue  = 0;

            // if on edge, counter = 6
            // if in corner, counter = 4
            // if in middle, counter = 9
            float counter = 0.00;

            for(int x = -1; x < 2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    // navigate the position of neighbouring pixels around [i][j]
                    int curX = i + x;
                    int curY = j + y;

                    // if the pixels are on the edge, continue.
                    if(curX < 0 || curX > (height - 1) || curY < 0 || curY > (width -1))
                    {
                        continue;
                    }

                    // adding total Red colour for each [x][y]neighbouring pixel of [i][j] pixel.
                    totalRed =  totalRed + image[curX][curY].rgbtRed;

                    // adding total Green colour for each [x][y]neighbouring pixel of [i][j] pixel.
                    totalGreen = totalGreen + image[curX][curY].rgbtGreen;

                    // adding total Blue colour for each [x][y]neighbouring pixel of [i][j] pixel.
                    totalBlue = totalBlue + image[curX][curY].rgbtBlue;

                    // we loop a total of 9 times, through a 3x3 grid of pixels for each [i][j] pixel.
                    // when the y-loop reach (y = 1; y < 2; y++) the counter = 3
                    counter++;
                }
                // finally, caluculating average for each rgbt value to produce blur.
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);

                // Above three rgbt values make up the temp[i][j].
            }
        }
    }

    // save changes from temp[i][j] to image[i][j].
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
