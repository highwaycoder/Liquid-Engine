#ifndef __H_MD2MODEL__
#define __H_MD2MODEL__

#include <stdint.h>
#include "Model.h"

class MD2Model : Model
{
	private:
		/* MD2 Header Data */
		uint32_t ident; /* Must by "IDP2" */
		uint32_t version;
		uint32_t texture_width;
		uint32_t texture_height;
		uint32_t frame_size; /* in bytes */
		uint32_t num_textures;
		uint32_t num_vertices;
		uint32_t num_texcoords;
		uint32_t num_triangles;
		uint32_t num_gl_commands; /* I'm probably going to ignore this */
		uint32_t num_frames;
		uint32_t offset_texture_names; /* each texture name is unsigned char[64] */
		uint32_t offset_texcoords;
		uint32_t offset_triangles;
		uint32_t offset_frames;
		uint32_t offset_gl_commands;
		uint32_t offset_end;



	public:
		MD2Model();
		~MD2Model();

		void load(const char* path);
};


#endif
