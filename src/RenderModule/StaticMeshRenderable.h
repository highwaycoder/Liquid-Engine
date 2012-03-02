#ifndef __H_STATICMESHRENDERABLE__
#define __H_STATICMESHRENDERABLE__

#include <stdint.h>

class ModelMesh;

class StaticMeshRenderable
{
	private:
		void* m_vertices;
		void* m_texcoords;
		void* m_elements;

		uint32_t m_num_vertices;
		uint32_t m_num_texcoords;
		uint32_t m_num_elements;

		uint32_t m_vbo_vertices;
		uint32_t m_vbo_texcoords;
		uint32_t m_vbo_elements;

		bool has_texcoords;

		ModelMesh* m_mesh;
	public:
		StaticMeshRenderable(ModelMesh*);
		~StaticMeshRenderable();

		void render();
};

#endif
