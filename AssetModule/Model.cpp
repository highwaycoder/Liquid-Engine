#include "Model.h"

Model::Model()
{

}


void Model::addFace(Face& face)
{
	m_faces.push_back(face);
}

std::vector<Face> Model::getFaces() const
{
	std::vector<Face> faces(m_faces);

	return faces;
}

void Model::addVertex(Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void Model::addTextureCoordinate(TextureCoordinate& texture_coordinate)
{
	m_texture_coordinates.push_back(texture_coordinate);
}

void Model::addNormal(Normal& normal)
{
	m_normals.push_back(normal);
}

bool Model::isValid() const
{
	/* Get our index array counts */
	uint32_t vertices_length = m_vertices.size();
	uint32_t texture_coordinates_length = m_texture_coordinates.size();
	uint32_t normals_length = m_normals.size();

	/* Is this even a valid geometric primitive? */
	if ((vertices_length != texture_coordinates_length) || (vertices_length != normals_length))
		return false; /* invalid model */
	else
		return true;
}

enum GeometryType Model::getPrimitiveType() const
{
	return Invalid;
}
