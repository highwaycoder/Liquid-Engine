#include "TextureSample2D.h"

#include "AssetModule/Image.h"
#include <GL/gl.h>
#include <GL/glu.h>


TextureSample2D::TextureSample2D(Image& image)
{

	glGenTextures(1, &m_gltexture_handle);

	glBindTexture(GL_TEXTURE_2D, m_gltexture_handle);

	if (image.getBPP() == 32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getWidth(), image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getData());
	else if (image.getBPP() == 24)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.getData());


	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void TextureSample2D::useTexture()
{
	glBindTexture(GL_TEXTURE_2D, m_gltexture_handle);
}

TextureSample2D::~TextureSample2D()
{
	glDeleteTextures(1, &m_gltexture_handle);
}

