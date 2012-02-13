#include "Face.h"

Face::Face()
{
	
}

void Face::addVertex(Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void Face::addTextureCoordinate(TextureCoordinate& texture_coordinate)
{
	m_texture_coordinates.push_back(texture_coordinate);
}

void Face::addNormal(Normal& normal)
{
	m_normals.push_back(normal);
}

std::vector<Vertex> Face::getVertices() const
{
	std::vector<Vertex> vertices(m_vertices);

	return vertices;
}

std::vector<TextureCoordinate> Face::getTextureCoordinates() const
{
	std::vector<TextureCoordinate> texture_coordinates(m_texture_coordinates);

	return texture_coordinates;
}

std::vector<Normal> Face::getNormals() const
{
	std::vector<Normal> normals(m_normals);

	return normals;
}

