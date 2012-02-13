#include "Vertex.h"

Vertex::Vertex()
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;
}

Vertex::Vertex(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

float Vertex::getX() const
{
	return m_x;
}

float Vertex::getY() const
{
	return m_y;
}

float Vertex::getZ() const
{
	return m_z;
}
