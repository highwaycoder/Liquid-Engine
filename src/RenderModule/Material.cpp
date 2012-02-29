#include "Material.h"

#include <GLee.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>

Material::Material()
{
	m_program_id = glCreateProgram();
}

Material::~Material()
{
	glDeleteProgram(m_program_id);
}

void Material::AttachShader(Shader* shader)
{
	glAttachShader(m_program_id, shader->getShaderID());
}

void Material::DetachShader(Shader* shader)
{
	glDetachShader(m_program_id, shader->getShaderID());
}

void Material::LinkMaterial()
{
	glLinkProgram(m_program_id);
}

void Material::UseMaterial()
{
	glUseProgram(m_program_id);
}

