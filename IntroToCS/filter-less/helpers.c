#include "helpers.h"

/*
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
*/

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            uint32_t grey = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtRed = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{   
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            uint32_t new_red   = (image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189);
            uint32_t new_green = (image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168);
            uint32_t new_blue  = (image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131);

            image[i][j].rgbtRed     = (new_red > 0xFF) ? 0xFF : new_red;
            image[i][j].rgbtGreen   = (new_green > 0xFF) ? 0xFF : new_green;
            image[i][j].rgbtBlue    = (new_blue > 0xFF) ? 0xFF : new_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   
    for(int i = 0; i < height; i++){
        for(int j = 0; j < (width / 2); j++){
            uint32_t current_red    = image[i][j].rgbtRed;
            uint32_t current_green  = image[i][j].rgbtGreen;
            uint32_t current_blue   = image[i][j].rgbtBlue;

            image[i][j].rgbtRed     = image[i][width - j].rgbtRed;
            image[i][j].rgbtGreen   = image[i][width - j].rgbtGreen;
            image[i][j].rgbtBlue    = image[i][width - j].rgbtBlue;

            image[i][width - j].rgbtRed    = current_red;
            image[i][width - j].rgbtBlue   = current_blue;
            image[i][width - j].rgbtGreen  = current_green;
        }
    }
    return;
}

/*
FUNCTION:
    Will determine if the pixel is either corner (top left/right, bottom left/right)

INPUTS:
    Inputs: Image Height, and Width. Current pixel's place in that height and width

RETURNS: 
    0 => Pixel is not a corner
    1 => Pixel is Top Left Corner
    2 => Pixel is Top Right Corner
    3 => Pixel is Bottom Left Corner
    4 => Pixel is Bottom Right Corner
*/

uint32_t corner_check(const uint32_t image_height, const uint32_t image_width, const uint32_t current_height, const uint32_t current_width){
    //Top Left
    if((current_height == 0) && (current_width == 0)){
        return 1;
    //Top Right
    } else if ((current_height == 0) && (current_width == image_width - 1)){
        return 2;
    //Bottom Left
    } else if ((current_height == image_height - 1) && (current_width == 0)){
        return 3;
    //Bottom Right
    } else if ((current_height == image_height -1) && (current_width == image_width - 1)){
        return 4;
    //Not a corner
    } else {
        return 0;
    }
}

/*
FUNCTION:
    Will determine if the pixel is on the border (top left/right, bottom left/right)
        => Will not return true for corners

INPUTS:
    Inputs: Image Height, and Width. Current pixel's place in that height and width

RETURNS: 
    0 => Pixel is not on a border or is a corner
    1 => Pixel is on the Top Border
    2 => Pixel is on the Left Border
    3 => Pixel is on the Right Border
    4 => Pixel is on the Bottom Border
*/

uint32_t border_check(const uint32_t image_height, const uint32_t image_width, const uint32_t current_height, const uint32_t current_width){
    //Top
    if(current_height == 0 && ((current_width != image_width - 1) && (current_width != 0))){
        return 1;
    //Left
    } else if(current_width == 0 && ((current_height != 0) && (current_height != image_height -1))){
        return 2;
    //Right
    } else if((current_width == image_width - 1) && ((current_height != 0) && (current_height != image_height - 1))){
        return 3;
    //Bottom
    } else if ((current_height == image_height - 1) && ((current_width != 0) && (current_width != image_width - 1))){
        return 4;
    } else {
        return 0;
    }
}

// void blur_corner(int corner, RGBTRIPLE image[height][width]){
//     switch(corner){
//         case 1: //Top Left
//             break;
//         case 2: //Top Right
//             break;
//         case 3: //Bottom Left
//             break;
//         case 4: //Bottom Right
//             break;
//         default:
//             break;
//     }
// }

void blur_border(int corner, RGBTRIPLE image[height][width]){
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            uint32_t is_corner = corner_check(height, width, i, j);
            
            uint32_t is_border = border_check(height, width, i, j);

            if(is_corner){
                // blur_corner(is_corner, image[i][j]);
                continue;
            } else if (is_border){
                // blur_border(is_border, image[i][j]);
                continue;
            } else {
                //Not border or a corner
                uint32_t sum_red = 0, sum_green = 0, sum_blue = 0;

                for(int inner_i = -1; inner_i < 2; inner_i++){
                    for(int inner_j = -1; inner_j < 2; inner_j++){
                        sum_red     += image[i + inner_i][j + inner_j].rgbtRed;
                        sum_green   += image[i + inner_i][j + inner_j].rgbtGreen;
                        sum_blue    += image[i + inner_i][j + inner_j].rgbtBlue;
                    }
                }
               
                image[i][j].rgbtRed = sum_red / 9;
                image[i][j].rgbtGreen = sum_green / 9;
                image[i][j].rgbtBlue = sum_blue / 9;
            }
        }
    }
    return;
}
