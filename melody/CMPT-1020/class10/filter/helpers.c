/**
 * Written by Tait Hoyem <tait@tait.tech>
 *
 * All the rest written by Harvard University
 * Proud of my work today!
 */

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            // casting to float to get more accurate float from /3 calc; this makes the round more correct :)
            int avg = round((float)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width/2; ++j)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-(j+1)];
            image[i][width-(j+1)] = temp;
        }
    }
    return;
}

// average 9 squares around pixel
RGBTRIPLE avg9(int height, int width, RGBTRIPLE image[height][width], int y, int x)
{
    RGBTRIPLE avged;
    int r = 0, g = 0, b = 0, count = 0;

    for (int i = y-1; i <= y+1; ++i)
    {
        for (int j = x-1; j <= x+1; ++j)
        {
            if (i >= 0 && i < height && j >= 0 && j < width)
            {
                ++count;
                r += image[i][j].rgbtRed;
                g += image[i][j].rgbtGreen;
                b += image[i][j].rgbtBlue;
            }
        }
    }
    // force more accurate avg with (float)
    avged.rgbtRed = round((float)r/count);
    avged.rgbtBlue = round((float)b/count);
    avged.rgbtGreen = round((float)g/count);
    return avged;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary storage so the original image remains unprocessed during the bluring
    RGBTRIPLE blured[height][width];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            // save to temp blured
            blured[i][j] = avg9(height, width, image, i, j);
        }
    }
    // copy blured into image :)
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            image[i][j] = blured[i][j];
        }
    }
    return;
}

int Gx[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};
int Gy[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
};

RGBTRIPLE compute_gxy(int height, int width, RGBTRIPLE image[height][width], int y, int x)
{
    RGBTRIPLE gxy;

    // ii, ji and i index and j index (0-2) for which iteration of the loop it is in.
    int rgx = 0, ggx = 0, bgx = 0, rgy = 0, ggy = 0, bgy = 0;
    int ii, ji, rgxy, ggxy, bgxy;
    for (int i = y-1; i <= y+1; ++i)
    {
        for (int j = x-1; j <= x+1; ++j)
        {
            if (i < 0 || i >= height || j < 0 || j >= width)
            {
                continue;
            }
            ii = i-(y-1), ji = j-(x-1);
            rgx += (image[i][j].rgbtRed * Gx[ii][ji]);
            ggx += (image[i][j].rgbtGreen * Gx[ii][ji]);
            bgx += (image[i][j].rgbtBlue * Gx[ii][ji]);
            rgy += (image[i][j].rgbtRed * Gy[ii][ji]);
            ggy += (image[i][j].rgbtGreen * Gy[ii][ji]);
            bgy += (image[i][j].rgbtBlue * Gy[ii][ji]);
        }
    }

    rgxy = round(hypot(rgx, rgy));
    ggxy = round(hypot(ggx, ggy));
    bgxy = round(hypot(bgx, bgy));

    gxy.rgbtRed = rgxy > 255 ? 255 : rgxy;
    gxy.rgbtGreen = ggxy > 255 ? 255 : ggxy;
    gxy.rgbtBlue = bgxy > 255 ? 255 : bgxy;
    return gxy;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // copy pixels to second image to leave first one unprocessed
    RGBTRIPLE edge_detected[height][width];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            edge_detected[i][j] = compute_gxy(height, width, image, i, j);
        }
    }
    // copy information to original image
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            image[i][j] = edge_detected[i][j];
        }
    }
    return;
}
