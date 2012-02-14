#include "Face.h"

Face::Face()
{
	
}

void Face::addVertex(uint32_t vertex)
{
	m_vertices.push_back(vertex);
}

void Face::addTextureCoordinate(uint32_t texture_coordinate)
{
	m_texture_coordinates.push_back(texture_coordinate);
}

void Face::addNormal(uint32_t normal)
{
	m_normals.push_back(normal);
}

std::vector<uint32_t> Face::getVertices() const
{
	std::vector<uint32_t> vertices(m_vertices);

	return vertices;
}

std::vector<uint32_t> Face::getTextureCoordinates() const
{
	std::vector<uint32_t> texture_coordinates(m_texture_coordinates);

	return texture_coordinates;
}

std::vector<uint32_t> Face::getNormals() const
{
	std::vector<uint32_t> normals(m_normals);

	return normals;
}

enum GeometryType Face::getGeometryType() const
{
	/* Get our index array counts */
	uint32_t vertices_length = m_vertices.size();
	uint32_t texture_coordinates_length = m_texture_coordinates.size();
	uint32_t normals_length = m_normals.size();

	/* Is this even a valid geometric primitive? */
	if ((vertices_length != texture_coordinates_length) || (vertices_length != normals_length))
	{
		return Invalid;
	}

	/* All counts are equal, but if there's 2 or less indices, something is fucked */
	switch (vertices_length)
	{
		case 0:
			return Invalid;
		case 1:
			return Invalid;
		case 2:
			return Invalid;
		case 3:
			return Triangle;
		case 4:
			return Quad;
		default:
			return Polygon;
	}
}
