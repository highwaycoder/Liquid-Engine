#include "BitmapLoader.h"

struct Bitmap loadBMP(const char* path)
{
	FILE* file;
	int file_size = -1;
	char* file_memory = NULL;
	struct Bitmap bitmap;
	uint8_t bytes_per_pixel;
	uint32_t pixel_data_offset;
	uint32_t width;
	uint32_t height;
	uint64_t pixel_data_size;

	/* Open the model file */
	file = fopen(path, "rb");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file into memory */
	file_memory = (char*)(malloc(sizeof(char) * file_size));
	fread(file_memory, sizeof(char), file_size, file);

	/* We no longer need this file open */
	fclose(file);

	/* Copy the file header into memory */
	memcpy(&bitmap.file_header, file_memory, BITMAP_FILEHEADER_SIZE);

	/* Copy the info header into memory */
	memcpy(&bitmap.info_header, (file_memory + BITMAP_FILEHEADER_SIZE), BITMAP_INFOHEADER_SIZE);

	printf("Bytes: %s\n", bitmap.file_header.signature);
	//printf("Size: %u\n", bitmap.file_header.file_size);
	printf("off: %x\n", bitmap.file_header.data_offset[0]);
	printf("off: %x\n", bitmap.file_header.data_offset[1]);
	printf("off: %x\n", bitmap.file_header.data_offset[2]);
	printf("off: %x\n", bitmap.file_header.data_offset[3]);

	printf("BPP: %i\n", bitmap.info_header.bits_per_pixel);

	/* Calculate the number of bytes per pixel so we know pixel size */
	bytes_per_pixel = (bitmap.info_header.bits_per_pixel / 8);

	/* Set the pixel data offset */
	pixel_data_offset = bitmap.file_header.data_offset[0] + (bitmap.file_header.data_offset[1] * 256) + (bitmap.file_header.data_offset[2] * 65536) + (bitmap.file_header.data_offset[3] * 16777216);

	printf("Data Offset: %u\n", pixel_data_offset);


	/* Set image dimensions */
	width = bitmap.info_header.width;
	height = bitmap.info_header.height;

	/* Calculate pixel data size */
	pixel_data_size = width * height * bytes_per_pixel;

	/* Allocate memory for our pixel data */
	bitmap.pixel_data = (unsigned char*)malloc(sizeof(char) * pixel_data_size);

	/* Start copying pixels from file memory to our allocated memory */
	for (int offset = 0; offset < pixel_data_size; offset = offset + bytes_per_pixel)
	{
		bitmap.pixel_data[offset] = file_memory[pixel_data_offset + offset + 2];
		bitmap.pixel_data[offset + 1] = file_memory[pixel_data_offset + offset + 1];
		bitmap.pixel_data[offset + 2] = file_memory[pixel_data_offset + offset];
	}	

	/* Free the file memory */
	free(file_memory);

	return bitmap;
}

