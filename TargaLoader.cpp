#include "TargaLoader.h"

struct Targa loadTGA(const char* path)
{
	FILE* file;
	int file_size = -1;
	char* file_memory = NULL;
	struct Targa targa;

	/* Everything we need to calculate pixel data field size and position */
	uint8_t bytes_per_pixel;
	uint16_t pixel_data_offset;
	uint16_t pixel_data_size;

	/* Color map position and length */
	uint16_t color_map_offset;
	uint16_t color_map_size; //in bytes, so this will be based on number of entires and bpp

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

	/* Read the header into memory */
	memcpy(&targa.header, file_memory, TARGA_HEADER_SIZE);


	printf("Size: %u, %u\n", targa.header.image_specifications.image_width, targa.header.image_specifications.image_height);
	printf("BPP: %i\n", targa.header.image_specifications.image_bpp);
	printf("Color Map Type: %i\n", targa.header.color_map_type);
	printf("Image Type: %i\n", targa.header.image_type);
	printf("ID Length: %i\n", (int)targa.header.id_length);
	printf("Origin: %u,%u\n", targa.header.image_specifications.x_origin, targa.header.image_specifications.y_origin);

	/* Calculate color map size and offset [Note: The color map doesn't necessarily exist (0s indicate that)]*/
	color_map_offset = (256 * targa.header.color_map_specifications.color_map_offset[1]) + targa.header.color_map_specifications.color_map_offset[0];
	color_map_size = (targa.header.color_map_specifications.color_map_bpp / 8) * ((256 * targa.header.color_map_specifications.color_map_length[1]) + targa.header.color_map_specifications.color_map_length[0]);

	printf("Color Map Offset: %u\n", color_map_offset);
	printf("Color Map Length: %u\n", color_map_size);

	/* Calculate pixel data size and offset */
	bytes_per_pixel = targa.header.image_specifications.image_bpp / 8; //assuming that BPP is multiple of 8. Probably need to check on that later
	pixel_data_offset = TARGA_HEADER_SIZE + color_map_size;
	pixel_data_size = (targa.header.image_specifications.image_width * targa.header.image_specifications.image_height * bytes_per_pixel);

	/* Allocate pixel data space */
	targa.pixel_data = (unsigned char*)malloc(sizeof(char) * pixel_data_size);

	if (targa.header.image_type == TGA_UNCOMPRESSEDTRUECOLOR)
	{
		//Step one pixel at a time and copy
		for (uint16_t current_offset = pixel_data_offset; current_offset < (pixel_data_offset + pixel_data_size); current_offset = (current_offset + bytes_per_pixel))
		{
			targa.pixel_data[current_offset - pixel_data_offset] = file_memory[current_offset+2]; //Red
			targa.pixel_data[current_offset - pixel_data_offset + 1] = file_memory[current_offset+1]; //Green
			targa.pixel_data[current_offset - pixel_data_offset + 2] = file_memory[current_offset]; //Blue

			printf("Pixel found!\n");

			/* Do we have an alpha channel? */
			if (bytes_per_pixel == 4)
				targa.pixel_data[current_offset - pixel_data_offset + 3] = file_memory[current_offset+3]; //Alpha
		}
	}

	/* Free the file memory */
	free(file_memory);

	return targa;
}

