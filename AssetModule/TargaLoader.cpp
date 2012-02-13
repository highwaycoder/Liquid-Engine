#include "TargaLoader.h"

struct Targa loadTGA(const char* path)
{
	FILE* file;
	int file_size = -1;
	char* file_memory = NULL;
	struct Targa targa;

	/* Everything we need to calculate pixel data field size and position */
	uint8_t bytes_per_pixel;
	uint64_t pixel_data_offset;
	uint64_t pixel_data_size;

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
	color_map_offset = (256 * targa.header.color_map_specifications.color_map_offset[1]) + targa.header.color_map_specifications.color_map_offset[0] + targa.header.id_length;
	color_map_size = (targa.header.color_map_specifications.color_map_bpp / 8) * ((256 * targa.header.color_map_specifications.color_map_length[1]) + targa.header.color_map_specifications.color_map_length[0]);

	printf("Color Map Offset: %u\n", color_map_offset);
	printf("Color Map Length: %u\n", color_map_size);

	/* Calculate pixel data size and offset */
	bytes_per_pixel = targa.header.image_specifications.image_bpp / 8; //assuming that BPP is multiple of 8. Probably need to check on that later
	pixel_data_offset = TARGA_HEADER_SIZE + color_map_size + targa.header.id_length;
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

			/* Do we have an alpha channel? */
			if (bytes_per_pixel == 4)
				targa.pixel_data[current_offset - pixel_data_offset + 3] = file_memory[current_offset+3]; //Alpha
		}
	}
	else if (targa.header.image_type == TGA_RLETRUECOLOR)
	{
		/*
		Here's the bitch and a half situation, the origin can be at any corner of the image, and RLE works from that origin.
		Top-left and Bottom-left, I've seen and sampled, so those will be tested, but all should be functional.
		Unfortunately, this origin fuckery might make this algorithm look kind of messy. C'est la vie.
		We're going to be mirroring the image data as necessary
		*/

		uint64_t file_offset = pixel_data_offset; //we're going to keep track of our progress through file data separate from finalized image data
		uint64_t memory_offset = 0; //this is our offset within our finalized pixel data
		uint8_t RLE_header;

		/* Keep track of which mirrorings we need */
		bool mirror_y = false;
		bool mirror_x = false;

		/* These are for my own convenience. Memory is cheap. Bite me. */
		uint16_t width = targa.header.image_specifications.image_width;
		uint16_t height = targa.header.image_specifications.image_height;

		/* We need these for keeping track of how many pixels we've populated out of the total */
		uint64_t current_pixel_count = 0;
		uint64_t total_pixel_count = width * height;


		/* Calculate which direction we'll be going */
		if (targa.header.image_specifications.x_origin == targa.header.image_specifications.image_width)
			mirror_x = true;
		else if (targa.header.image_specifications.x_origin == 0)
			mirror_x = false;

		if (targa.header.image_specifications.y_origin == targa.header.image_specifications.image_height)
			mirror_y = true;
		else if (targa.header.image_specifications.x_origin == 0)
			mirror_y = false;
		

		/* While we have pixels left that haven't been populated, parse RLE headers */
		while (current_pixel_count < total_pixel_count)
		{
			RLE_header = file_memory[file_offset];

			if (RLE_header < 128) //this header's value + 1 raw pixels follows
			{
				uint8_t number_of_raw_pixels = (RLE_header + 1);

				for (uint64_t current_pixel = 0; current_pixel < number_of_raw_pixels; current_pixel++)
				{
					targa.pixel_data[memory_offset] = file_memory[file_offset + 3];//Red
					targa.pixel_data[memory_offset + 1] = file_memory[file_offset + 2];//Blue 
					targa.pixel_data[memory_offset + 2] = file_memory[file_offset + 1];//Green

					if (bytes_per_pixel == 4)
						targa.pixel_data[memory_offset + 3] = file_memory[file_offset + 4];//Alpha					

					/* Increment pixel count */
					current_pixel_count++;

					/* Move our file index and our memory index forward */
					file_offset = file_offset + bytes_per_pixel;
					memory_offset = memory_offset + bytes_per_pixel;
				}

				printf("fucccccccccked RLE Header: %u\n", RLE_header);

				/* Grab the next RLE header */
				file_offset = file_offset + 1;
			}
			else if (RLE_header >= 128) //this header value - 127 pixels follow of the following color
			{
				uint8_t number_of_pixels = RLE_header - 127;


				for (uint64_t current_pixel = 0; current_pixel < number_of_pixels; current_pixel++)
				{
					targa.pixel_data[memory_offset] = file_memory[file_offset + 3];//Red
					targa.pixel_data[memory_offset + 1] = file_memory[file_offset + 2];//Blue 
					targa.pixel_data[memory_offset + 2] = file_memory[file_offset + 1];//Green

					if (bytes_per_pixel == 4)
						targa.pixel_data[memory_offset + 3] = file_memory[file_offset + 4];//Alpha

					/* Move our memory index forward */
					memory_offset = memory_offset + bytes_per_pixel;

					/* Increment pixel count */
					current_pixel_count++;
				}

				file_offset = file_offset + (bytes_per_pixel) + 1;
			}
		}

	}


	/* Free the file memory */
	free(file_memory);

	return targa;
}

