#include "Normal.h"

Normal::Normal()
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;
}

Normal::Normal(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

float Normal::getX() const
{
	return m_x;
}

float Normal::getY() const
{
	return m_y;
}

float Normal::getZ() const
{
	return m_z;
}
