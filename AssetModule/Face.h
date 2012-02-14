#ifndef __H_FACE__
#define __H_FACE__

#include <vector>
#include <stdint.h>

#include "GeometryType.h"

class Face
{
	private:
		std::vector<uint32_t> m_vertices;
		std::vector<uint32_t> m_texture_coordinates;
		std::vector<uint32_t> m_normals;

	public:
		Face();

		void addVertex(uint32_t);
		void addTextureCoordinate(uint32_t);
		void addNormal(uint32_t);

		std::vector<uint32_t> getVertices() const;
		std::vector<uint32_t> getTextureCoordinates() const;
		std::vector<uint32_t> getNormals() const;

		enum GeometryType getGeometryType() const;
};

#endif

