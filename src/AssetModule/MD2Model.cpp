#include "MD2Model.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

MD2Model::MD2Model()
{


}

MD2Model::~MD2Model()
{

}

void MD2Model::load(const char* path)
{
	FILE* file;
	int file_size = -1;
	void* file_memory = NULL;

	/* Open the model file */
	file = fopen(path, "r");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file into memory */
	file_memory = malloc(sizeof(char) * (file_size + 1));
	fread(file_memory, sizeof(unsigned char), file_size, file);

	/* We no longer need this file open */
	fclose(file);

	/* Populate header values */
	memcpy(&ident, file_memory, 4);
	memcpy(&version, file_memory+4, 4);
	memcpy(&texture_width, file_memory+8, 4);
	memcpy(&texture_height, file_memory+12, 4);
	memcpy(&frame_size, file_memory+16, 4);
	memcpy(&num_textures, file_memory+20, 4);
	memcpy(&num_vertices, file_memory+24, 4);
	memcpy(&num_texcoords, file_memory+28, 4);
	memcpy(&num_triangles, file_memory+32, 4);
	memcpy(&num_gl_commands, file_memory+36, 4);
	memcpy(&num_frames, file_memory+40, 4);
	memcpy(&offset_texture_names, file_memory+44, 4);
	memcpy(&offset_texcoords, file_memory+48, 4);
	memcpy(&offset_triangles, file_memory+52, 4);
	memcpy(&offset_frames, file_memory+56, 4);
	memcpy(&offset_gl_commands, file_memory+60, 4);
	memcpy(&offset_end, file_memory+64, 4);

	printf("Identifier (hex): %x\n", ident);
	printf("Identifier (int): %i\n", ident);
	printf("Version (hex): %x\n", version);
	printf("Version (int): %i\n", version);
	printf("Texture Width (hex): %x\n", texture_width);
	printf("Texture Width (int): %i\n", texture_width);
	printf("Texture Height (hex): %x\n", texture_height);
	printf("Texture Height (int): %i\n", texture_height);


	printf("Frame Size (int): %i\n", frame_size);
	printf("Num Textures (int): %i\n", num_textures);
	printf("Num Vertices (int): %i\n", num_vertices);
	printf("Num TexCoords (int): %i\n", num_texcoords);
	printf("Num Triangles (int): %i\n", num_triangles);
	printf("Num GL cmds (int): %i\n", num_gl_commands);
	printf("Num Frames (int): %i\n", num_frames);



}
