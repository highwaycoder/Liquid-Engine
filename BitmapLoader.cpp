#include "BitmapLoader.h"

void loadBMP(const char* path)
{
	FILE* file;
	int file_size = -1;
	char* file_memory = NULL;
	struct Bitmap bitmap;

	/* Open the model file */
	file = fopen(path, "rb");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file into memory */
	file_memory = (char*)(malloc(sizeof(char) * file_size));
	fread(file_memory, sizeof(char), file_size, file);

	/* Copy the file header into memory */
	memcpy(&bitmap.file_header, file_memory, BITMAP_FILEHEADER_SIZE);

	/* Copy the info header into memory */
	memcpy(&bitmap.info_header, (file_memory + BITMAP_FILEHEADER_SIZE), BITMAP_INFOHEADER_SIZE);

	/* We no longer need this file open */
	fclose(file);

	printf("Bytes: %s\n", bitmap.file_header.signature);
	printf("BPP: %i\n", bitmap.info_header.bits_per_pixel);

	/* Free the file memory */
	free(file_memory);
}

