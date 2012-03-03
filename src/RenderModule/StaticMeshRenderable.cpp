#include "StaticMeshRenderable.h"

#include <GLee.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include "AssetModule/ModelMesh.h"


StaticMeshRenderable::StaticMeshRenderable(ModelMesh* mesh)
{
	void* m_vertices;
	void* m_normals;
	void* m_texcoords;
	void* m_elements;


	has_texcoords = false;
	has_normals = false;

	/* Do we have tex coords? */
	if (mesh->hasTextureCoordinates())
		has_texcoords = true;

	/* Normals? */
	if (mesh->hasNormals())
		has_normals = true;

	if (has_texcoords)
	{
		printf("godaamnint\n");
		exit(0);
	}

	if (has_normals)
	{
		//printf("godaamnint\n");
		//exit(0);
	}


	/* Allocate VBOs */
	glGenBuffers(1, &m_vbo_vertices);
	glGenBuffers(1, &m_vbo_elements);

	if (has_normals)
		glGenBuffers(1, &m_vbo_normals);

	if (has_texcoords)
		glGenBuffers(1, &m_vbo_texcoords);

	/* Store attributes */
	m_num_vertices = mesh->getVertexCount();
	m_num_normals = mesh->getNormalCount();
	m_num_texcoords = mesh->getTextureCoordinateCount();
	m_num_elements = mesh->getTriangleCount() * 3;

	/* Copy data to the VBOs */
	uint32_t vertices_size = mesh->getVertexCount() * sizeof(struct Vertex);
	uint32_t normals_size = mesh->getNormalCount() * sizeof(struct Normal);
	uint32_t texcoords_size = mesh->getTextureCoordinateCount() * sizeof(struct TextureCoordinate);
	uint32_t triangles_size = mesh->getTriangleCount() * sizeof(struct Triangle);

	const std::vector<struct Vertex>& vertices = mesh->getVertices();
	const std::vector<struct Normal>& normals = mesh->getNormals();
	const std::vector<struct Triangle>& triangles = mesh->getTriangles();	
	const std::vector<struct TextureCoordinate>& texcoords = mesh->getTextureCoordinates();

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, vertices_size, &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangles_size, &triangles[0], GL_STATIC_DRAW);

	if (has_normals)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo_normals);
		glBufferData(GL_ARRAY_BUFFER, normals_size, &normals[0], GL_STATIC_DRAW);
	}

	if (has_texcoords)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo_texcoords);
		glBufferData(GL_ARRAY_BUFFER, texcoords_size, &texcoords[0], GL_STATIC_DRAW);
	}

	/* Unbind buffer */
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/* Store a reference to this modelmesh in case we need it again. */
	m_mesh = mesh;
}

StaticMeshRenderable::~StaticMeshRenderable()
{
	glDeleteBuffers(1, &m_vbo_vertices);
	glDeleteBuffers(1, &m_vbo_texcoords);
	glDeleteBuffers(1, &m_vbo_elements);
}

void StaticMeshRenderable::render()
{
	//if (GL_ARB_vertex_buffer_object)
	{
		//printf("fucking shit\n");
		//exit(0);
	}
	//else
	{
		//printf("goddamnit\n");
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo_vertices);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	if (has_normals)
	{
		glEnableClientState(GL_NORMAL_ARRAY);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo_normals);
		glNormalPointer(GL_FLOAT, 0, 0);
	}


	if (has_texcoords)
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo_texcoords);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
	}

	glEnableClientState(GL_VERTEX_ARRAY);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo_elements);
		glDrawElements(GL_TRIANGLES, m_num_elements, GL_UNSIGNED_INT, 0);

	glDisableClientState(GL_VERTEX_ARRAY);

	if (has_normals)
	{
		glDisableClientState(GL_NORMAL_ARRAY);
	}

	if (has_texcoords)
	{
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
