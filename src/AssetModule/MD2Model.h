#ifndef __H_MD2MODEL__
#define __H_MD2MODEL__

#include <stdint.h>
#include "Model.h"

struct MD2Skin
{
	char name[64];
};

struct MD2TextureCoordinate
{
	uint16_t s; /* Divide by width to tranform to U value (UV) */
	uint16_t t; /* Divide by height to tranform to V value (UV) */
};

struct MD2Vertex
{
	unsigned char vertex[3]; /* multiply by scaling vector for current frame for real value */
	unsigned char light_normal_index; 
};

struct MD2Triangle
{
	uint16_t vertex_index[3];
	uint16_t texcoord_index[3];
};

struct MD2Frame
{
	float scale[3];
	float translate[3];
	char name[16];
};

class MD2Model : Model
{
	private:
		/* MD2 Header Data */
		uint32_t md2_ident; /* Must by "IDP2" */
		uint32_t md2_version;
		uint32_t md2_texture_width;
		uint32_t md2_texture_height;
		uint32_t md2_frame_size; /* in bytes */
		uint32_t md2_num_textures;
		uint32_t md2_num_vertices;
		uint32_t md2_num_texcoords;
		uint32_t md2_num_triangles;
		uint32_t md2_num_gl_commands; /* I'm probably going to ignore this */
		uint32_t md2_num_frames;
		uint32_t md2_offset_texture_names; /* each texture name is unsigned char[64] */
		uint32_t md2_offset_texcoords;
		uint32_t md2_offset_triangles;
		uint32_t md2_offset_frames;
		uint32_t md2_offset_gl_commands;
		uint32_t md2_offset_end;

		/* MD2 Data */
		struct MD2Skin* md2_skins;
		struct MD2Frame* md2_frames;
		struct MD2TextureCoordinate* md2_texcoords;

		/* Generalized Model Data */
		struct TextureCoordinate* gen_texcoords;
		struct Triangle* gen_triangles;

	public:
		MD2Model();
		~MD2Model();

		void load(const char* path);
};


#endif
