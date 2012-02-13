#ifndef __H_BITMAP__
#define __H_BITMAP__

#include <stdint.h>

#define BITMAP_FILEHEADER_SIZE 14
#define BITMAP_INFOHEADER_SIZE 40

/* Compression types! */
typedef enum
{
	BI_RGB = 0,
	BI_RLE8 = 1,
	BI_RLE4 = 2,
	BI_BITFIELDS = 3,
	BI_JPEG = 4,
	BI_PNG = 5,
	BI_ALPHABITFIELDS = 6
} bitmap_compression_type;

struct BITMAPFILEHEADER
{
	unsigned char signature[2]; //should be "BM" typically
	unsigned char file_size[4];
	unsigned char first_reserved_block[2]; //reserved by the app that creates the bitmap
	unsigned char second_reserved_block[2];
	unsigned char data_offset[4]; //where in the file does the data begin
};

/* This is basically the Coca Cola Classic of DIB headers, so this should be all that is needed for typical support */
struct BITMAPINFOHEADER
{
	uint32_t header_size; //should be 40 bytes for this header type
	int32_t width;
	int32_t height;
	uint16_t number_of_color_planes; //must be 1. Fucked if I know why.
	uint16_t bits_per_pixel; //1, 4, 8, 16, 24, and 32 are typical values
	uint32_t compression_type; //defined above
	uint32_t bitmap_size; //size of the actual bitmap data, not filesize
	int32_t horizontal_resolution; //pixels per meter.
	int32_t vertical_resolution; //pixels per meter.
	uint32_t number_of_colors; //0 defaults to 2^n. Again, not entirely sure what that means yet
	uint32_t number_of_important_colors; //apparently this is unused. 0 defaults to every color is important
};

struct Bitmap
{
	struct BITMAPFILEHEADER file_header;
	struct BITMAPINFOHEADER info_header;
	unsigned char* pixel_data;
};

#endif
