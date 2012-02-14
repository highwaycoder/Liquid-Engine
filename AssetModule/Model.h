#ifndef __H_MODEL__
#define __H_MODEL__

#include <vector>
#include <stdint.h>

#include "Vertex.h"
#include "TextureCoordinate.h"
#include "Normal.h"

#include "Face.h"

#include "GeometryType.h"

class Model
{
	private:
		std::vector<Face> m_faces;

		std::vector<Vertex> m_vertices;
		std::vector<TextureCoordinate> m_texture_coordinates;
		std::vector<Normal> m_normals;
	public:
		Model();

		void addFace(Face&);
		std::vector<Face> getFaces() const;

		void addVertex(Vertex&);
		void addTextureCoordinate(TextureCoordinate&);
		void addNormal(Normal&);

		bool isValid() const;

		enum GeometryType getPrimitiveType() const;
};

#endif

