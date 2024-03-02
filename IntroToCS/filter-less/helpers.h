#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

//Helper function for blur
uint32_t corner_check(const uint32_t image_height, const uint32_t image_width, const uint32_t current_height, const uint32_t current_width);
uint32_t border_check(const uint32_t image_height, const uint32_t image_width, const uint32_t current_height, const uint32_t current_width);
void blur_corner(int corner, RGBTRIPLE image[height][width]);