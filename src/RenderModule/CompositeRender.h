#ifndef __H_COMPOSITERENDER__
#define __H_COMPOSITERENDER__

#include "stdint.h"
#include "AssetModule/ModelMesh.h"
#include "StaticMeshRenderable.h"
class CompositeRender
{
	private:
		uint32_t m_render_width;
		uint32_t m_render_height;

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
