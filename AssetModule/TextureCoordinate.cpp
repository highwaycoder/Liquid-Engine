#include "TextureCoordinate.h"

TextureCoordinate::TextureCoordinate()
{
	m_u = 0.0;
	m_v = 0.0;
	m_w = 0.0;
}

TextureCoordinate::TextureCoordinate(float u, float v)
{
	m_u = u;
	m_v = v;
	m_w = 0.0;
}

TextureCoordinate::TextureCoordinate(float u, float v, float w)
{
	m_u = u;
	m_v = v;
	m_w = w;
}

float TextureCoordinate::getU() const
{
	return m_u;
}

float TextureCoordinate::getV() const
{
	return m_v;
}

float TextureCoordinate::getW() const
{
	return m_w;
}

