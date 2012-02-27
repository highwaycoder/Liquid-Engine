#include "ImageLoader.h"

#include <stdlib.h>
#include "TargaLoader.h"

Image* loadImage(const char* path)
{
	char* extension = NULL;
	Image* texture = NULL;

	struct Targa image = loadTGA(path);
	uint32_t width = image.header.image_specifications.image_width;
	uint32_t height = image.header.image_specifications.image_height;
	uint8_t bpp = image.header.image_specifications.image_bpp;
	const unsigned char* data = image.pixel_data;

	texture = new Image(height, width, bpp, data);

	return texture;
}
