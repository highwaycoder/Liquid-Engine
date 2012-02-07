#include "TargaLoader.h"

void loadTGA(const char* path)
{
	FILE* file;
	int file_size = -1;
	struct Targa targa;

	/* Open the model file */
	file = fopen(path, "rb");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	printf("size: %lu\n", sizeof(struct COLOR_MAP_SPECIFICATIONS));
	printf("size: %lu\n", sizeof(struct IMAGE_SPECIFICATIONS));
	printf("union size: %lu\n", sizeof(union x));

	/* Read the header into memory */
	fread(&targa.header, sizeof(char), TARGA_HEADER_SIZE, file);

	printf("Size: %u, %u\n", targa.header.image_specifications.image_width, targa.header.image_specifications.image_height);
	printf("BPP: %i\n", targa.header.image_specifications.image_bpp);

	/* We no longer need this file open */
	fclose(file);

}

