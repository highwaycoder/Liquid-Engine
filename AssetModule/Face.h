#ifndef __H_FACE__
#define __H_FACE__

#include <vector>

#include "Vertex.h"
#include "TextureCoordinate.h"
#include "Normal.h"

#include <stdio.h>

class Face
{
	private:
		std::vector<Vertex> m_vertices;
		std::vector<TextureCoordinate> m_texture_coordinates;
		std::vector<Normal> m_normals;

	public:
		Face();

		void addVertex(Vertex&);
		void addTextureCoordinate(TextureCoordinate&);
		void addNormal(Normal&);

		std::vector<Vertex> getVertices() const;
		std::vector<TextureCoordinate> getTextureCoordinates() const;
		std::vector<Normal> getNormals() const;

};

#endif

