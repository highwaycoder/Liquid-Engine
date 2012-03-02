#ifndef __H_COMPOSITERENDER__
#define __H_COMPOSITERENDER__

#include "stdint.h"
#include "StaticMeshRenderable.h"
#include "TextureSample2D.h"

class ModelMesh;

class CompositeRender
{
	private:
		uint32_t m_render_width;
		uint32_t m_render_height;

		uint32_t m_gltexture_handle;
		float rot;
		TextureSample2D* tex;

	public:
		CompositeRender();

		virtual void Render();
		
		ModelMesh* model;
		StaticMeshRenderable* renderable;

		uint32_t getWidth() { return m_render_width; }
		uint32_t getHeight() { return m_render_height; }
		
		void setWidth(uint32_t value) { m_render_width = value; }
		void setHeight(uint32_t value) { m_render_height = value; }
};

#endif
