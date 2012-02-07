#include "BitmapLoader.h"

void loadBMP(const char* path)
{
	FILE* file;
	int file_size = -1;
	struct Bitmap bitmap;

	/* Open the model file */
	file = fopen(path, "rb");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file header into memory */
	fread(&bitmap.file_header, sizeof(char), BITMAP_FILEHEADER_SIZE, file);

	/* Read the info header into memory */
	fread(&bitmap.info_header, sizeof(char), BITMAP_INFOHEADER_SIZE, file);

	printf("Bytes: %s\n", bitmap.file_header.signature);
	printf("BPP: %i\n", bitmap.info_header.bits_per_pixel);

	/* We no longer need this file open */
	fclose(file);

}

