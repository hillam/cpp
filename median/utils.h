#ifndef UTILS_H
#define UTILS_H

const int width = 495;
const int height = 557;	
const long num_pixels = width * height;

struct pixel{
	int r;
	int g;
	int b;
};

struct image{
	pixel pixels[num_pixels];
};

pixel median(pixel* pixels, int size);

#endif