#ifndef __TARGA_H__
#define __TARGA_H__

#define TARGA_HEADER_SIZE 18

#include <stdint.h>


/* Padding issues are forcing me to use chars for these fields instead of their uint16_t counterparts. Paddings increase size from 5 to 6 and fuck up everything. */
struct COLOR_MAP_SPECIFICATIONS
{
	unsigned char color_map_offset[2];
	unsigned char color_map_length[2]; //number of entries
	unsigned char color_map_bpp;
};

struct IMAGE_SPECIFICATIONS
{
	uint16_t x_origin;
	uint16_t y_origin;
	uint16_t image_width;
	uint16_t image_height;
	uint8_t image_bpp;
	unsigned char image_desciptor; //bits 3-0 give alpha chanel depth, 5-4 give direction. Not sure yet what that significance is
};

struct TARGAHEADER
{
	unsigned char id_length;
	unsigned char color_map_type;
	unsigned char image_type;
	struct COLOR_MAP_SPECIFICATIONS color_map_specifications;
	struct IMAGE_SPECIFICATIONS image_specifications;
};

struct Targa
{
	struct TARGAHEADER header;
	unsigned char* data;
};

#endif
