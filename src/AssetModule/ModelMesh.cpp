#include "ModelMesh.h"

#include <stdlib.h>
#include <stdint.h>
#include <vector>

#include <stdio.h>

ModelMesh::ModelMesh()
{

}

void ModelMesh::addVertex(struct Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void ModelMesh::addTextureCoordinate(struct TextureCoordinate& texcoord)
{
	if (!m_has_texcoords)
		m_has_texcoords = true;

	m_texcoords.push_back(texcoord);
}

void ModelMesh::addTriangle(struct Triangle& triangle)
{
	m_triangles.push_back(triangle);
}

