#include "VertexShader.h"

#include "AssetModule/ShaderSource.h"

#include <GLee.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>

VertexShader::VertexShader(ShaderSource* source)
{
	m_shader_id = glCreateShader(GL_VERTEX_SHADER);

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

VertexShader::~VertexShader()
{
	glDeleteShader(m_shader_id);
}
