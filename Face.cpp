#include "Face.h"

Face::Face()
{
	
}

void Face::addVertex(Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void Face::addTextureCoordinate(Vertex& texture_coordinate)
{
	m_texture_coordinates.push_back(texture_coordinate);
}

void Face::addNormal(Vertex& normal)
{
	m_normals.push_back(normal);
}

void Face::render()
{
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		for (int index = 0; index < m_vertices.size(); index++)
			glVertex3f(m_vertices[index].getX(), m_vertices[index].getY(), m_vertices[index].getZ());
	glEnd();
}

void Face::debug_print()
{
	printf("Face Definition:\n");

	for (int i = 0; i < m_vertices.size(); i++)
	{
		printf("V = %f, %f, %f\n", m_vertices[i].getX(), m_vertices[i].getY(), m_vertices[i].getZ());
	}
}
