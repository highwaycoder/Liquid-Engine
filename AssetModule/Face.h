#ifndef __H_FACE__
#define __H_FACE__

#include <vector>
#include <GL/gl.h>
#include "Vertex.h"

#include <stdio.h>

class Face
{
	private:
		std::vector<Vertex> m_vertices;
		std::vector<Vertex> m_texture_coordinates;
		std::vector<Vertex> m_normals;

	public:
		Face();

		void addVertex(Vertex&);
		void addTextureCoordinate(Vertex&);
		void addNormal(Vertex&);

		void render();

		void debug_print();
};

#endif

