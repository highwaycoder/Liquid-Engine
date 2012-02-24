#include "MD2Model.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

MD2Model::MD2Model()
{


}

MD2Model::~MD2Model()
{
	delete[] md2_skins;
	delete[] md2_frames;
	delete[] md2_texcoords;

	/* Clear vertex data from the frame */
	for (uint32_t frame_num = 0; frame_num < md2_num_frames; frame_num++)
		delete[] gen_frames[frame_num].vertices; 

	delete[] gen_frames;
	delete[] gen_texcoords;
	delete[] gen_triangles;
}

void MD2Model::load(const char* path)
{
	FILE* file;
	int file_size = -1;
	unsigned char* file_memory = NULL;

	/* Open the model file */
	file = fopen(path, "r");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file into memory */
	file_memory = (unsigned char*)malloc(sizeof(char) * file_size);
	fread(file_memory, sizeof(unsigned char), file_size, file);

	/* We no longer need this file open */
	fclose(file);

	/* Populate header values */
	memcpy(&md2_ident, file_memory, 4);
	memcpy(&md2_version, file_memory+4, 4);
	memcpy(&md2_texture_width, file_memory+8, 4);
	memcpy(&md2_texture_height, file_memory+12, 4);
	memcpy(&md2_frame_size, file_memory+16, 4);
	memcpy(&md2_num_textures, file_memory+20, 4);
	memcpy(&md2_num_vertices, file_memory+24, 4);
	memcpy(&md2_num_texcoords, file_memory+28, 4);
	memcpy(&md2_num_triangles, file_memory+32, 4);
	memcpy(&md2_num_gl_commands, file_memory+36, 4);
	memcpy(&md2_num_frames, file_memory+40, 4);
	memcpy(&md2_offset_texture_names, file_memory+44, 4);
	memcpy(&md2_offset_texcoords, file_memory+48, 4);
	memcpy(&md2_offset_triangles, file_memory+52, 4);
	memcpy(&md2_offset_frames, file_memory+56, 4);
	memcpy(&md2_offset_gl_commands, file_memory+60, 4);
	memcpy(&md2_offset_end, file_memory+64, 4);

	printf("Identifier (hex): %x\n", md2_ident);
	printf("Identifier (int): %i\n", md2_ident);
	printf("Version (hex): %x\n", md2_version);
	printf("Version (int): %i\n", md2_version);
	printf("Texture Width (hex): %x\n", md2_texture_width);
	printf("Texture Width (int): %i\n", md2_texture_width);
	printf("Texture Height (hex): %x\n", md2_texture_height);
	printf("Texture Height (int): %i\n", md2_texture_height);


	printf("Frame Size (int): %i\n", md2_frame_size);
	printf("Num Textures (int): %i\n", md2_num_textures);
	printf("Num Vertices (int): %i\n", md2_num_vertices);
	printf("Num TexCoords (int): %i\n", md2_num_texcoords);
	printf("Num Triangles (int): %i\n", md2_num_triangles);
	printf("Num GL cmds (int): %i\n", md2_num_gl_commands);
	printf("Num Frames (int): %i\n", md2_num_frames);

	/* Allocate arrays based on MD2 header values */
	md2_skins = new MD2Skin[md2_num_textures];
	md2_frames = new MD2Frame[md2_num_frames];
	md2_texcoords = new MD2TextureCoordinate[md2_num_texcoords];

	gen_frames = new Frame[md2_num_frames];
	gen_texcoords = new TextureCoordinate[md2_num_texcoords];
	gen_triangles = new Triangle[md2_num_triangles];

	/* Texture Names */
	for (uint32_t texture_num = 0; texture_num < md2_num_textures; texture_num++)
	{
		struct MD2Skin md2_skin;

		/* Calculate the offset to the current skin */
		uint32_t offset = md2_offset_texture_names + (sizeof(struct MD2Skin) * texture_num);

		/* Populate skin name */
		memcpy(&md2_skin, file_memory+offset, sizeof(struct MD2Skin));
	}

	/* Texture Coordinates */
	for (uint32_t texcoord_num = 0; texcoord_num < md2_num_texcoords; texcoord_num++)
	{
		struct MD2TextureCoordinate md2_texcoord;
		struct TextureCoordinate gen_texcoord;

		/* Calculate the offset to the current texture coordinate */
		uint32_t offset = md2_offset_texcoords + (sizeof(struct MD2TextureCoordinate) * texcoord_num);

		/* Populate ST values (still will need to be converted to UV) */
		memcpy(&md2_texcoord, file_memory+offset, sizeof(struct MD2TextureCoordinate));

		/* Convert to UV values and store in the generic Texture Coordinate struct */
		gen_texcoord.u = (float)md2_texcoord.s / md2_texture_width;
		gen_texcoord.v = 1.0f - ((float)md2_texcoord.t / md2_texture_height); /* Must be flipped! */

		printf("Coord %i (%i, %i)\n", texcoord_num, md2_texcoord.s, md2_texcoord.t);
		printf("Adj Coord %i (%f, %f)\n", texcoord_num, gen_texcoord.u, gen_texcoord.v);
	}

	/* Triangles */
	for (uint32_t triangle_num = 0; triangle_num < md2_num_triangles; triangle_num++)
	{
		struct MD2Triangle md2_triangle;
		struct Triangle gen_triangle;

		/* Calculate the offset to the current texture coordinate */
		uint32_t offset = md2_offset_triangles + (sizeof(struct MD2Triangle) * triangle_num);

		/* Populate MD2 Triangle */
		memcpy(&md2_triangle, file_memory+offset, sizeof(struct MD2Triangle));

		/* Create generic Triangle */
		gen_triangle.vertex_index[0] = md2_triangle.vertex_index[0];
		gen_triangle.vertex_index[1] = md2_triangle.vertex_index[1];
		gen_triangle.vertex_index[2] = md2_triangle.vertex_index[2];

		gen_triangle.texcoord_index[0] = md2_triangle.texcoord_index[0];
		gen_triangle.texcoord_index[1] = md2_triangle.texcoord_index[1];
		gen_triangle.texcoord_index[2] = md2_triangle.texcoord_index[2];

		printf("Triangle %i (%i, %i, %i)\n", triangle_num, gen_triangle.vertex_index[0], gen_triangle.vertex_index[1], gen_triangle.vertex_index[2]);
	}

	/* Frames */
	for (uint32_t frame_num = 0; frame_num < md2_num_frames; frame_num++)
	{
		struct MD2Frame md2_frame;
		struct Frame gen_frame;

		/* Calculate the offset to the current texture coordinate */
		uint32_t offset = md2_offset_frames + (md2_frame_size * frame_num);

		/* Populate MD2 Frame */
		memcpy(&md2_frame, file_memory+offset, sizeof(struct MD2Frame));

		/* Allocate Vertex Data */
		gen_frame.vertices = new Vertex[md2_num_vertices];

		/* Copy Frame Name (or rather, 64 bytes of it) */
		memcpy(&gen_frame.name, &md2_frame.name, 64);

		printf("Frame %i\n", frame_num);

		/* Frame vertices */
		for (uint32_t vertex_num = 0; vertex_num < md2_num_vertices; vertex_num++)
		{
			struct MD2Vertex md2_vertex;
			struct Vertex gen_vertex;

			/* Calculate vertex offset (this is an offset of the existing frame offset */
			uint32_t vertex_offset = offset + sizeof(MD2Frame) + (sizeof(MD2Vertex) * vertex_num);

			/* Copy vertex data */
			memcpy(&md2_vertex, file_memory+vertex_offset, sizeof(struct MD2Vertex));

			/* Convert the MD2 vertex into a properly scaled generic vertex */
			gen_vertex.x = (md2_vertex.vertex[0] * md2_frame.scale[0]) + md2_frame.translate[0];
			gen_vertex.y = (md2_vertex.vertex[1] * md2_frame.scale[1]) + md2_frame.translate[1];
			gen_vertex.z = (md2_vertex.vertex[2] * md2_frame.scale[2]) + md2_frame.translate[2];

			/* Store frame */
			gen_frame.vertices[vertex_num] = gen_vertex;

			printf("\tVertex (%f, %f, %f)\n", gen_vertex.x, gen_vertex.y, gen_vertex.z);
		}

		/* Store frame */
		gen_frames[frame_num] = gen_frame;
	}

	/* Free file memory */
	free(file_memory);
}

void MD2Model::debug()
{
	for (uint32_t frame_num = 0; frame_num < md2_num_frames; frame_num++)
	{
		for (uint32_t vertex_num = 0; vertex_num < md2_num_vertices; vertex_num++)
		{
			printf("F: %i | V: %f\n", frame_num, gen_frames[frame_num].vertices[vertex_num].x);
		}	
	}
}

