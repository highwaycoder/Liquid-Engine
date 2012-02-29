#include "FragmentShader.h"

#include "AssetModule/ShaderSource.h"

#include <GLee.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>

FragmentShader::FragmentShader(ShaderSource* source)
{
	m_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

	const char* src = source->getSource();
	glShaderSource(m_shader_id, 1, &src, NULL);

	glCompileShader(m_shader_id);

	int result;
	glGetShaderiv(m_shader_id, GL_COMPILE_STATUS, &result);

	if (result == GL_TRUE)
	{
		printf("successful\n");
	}
	else
	{
		printf("failed\n");
	}
}

FragmentShader::~FragmentShader()
{
	glDeleteShader(m_shader_id);
}
