#include "ModelMesh.h"

#include <stdlib.h>
#include <stdint.h>
#include <vector>

#include <stdio.h>

ModelMesh::ModelMesh()
{
	m_has_texcoords = false;
	m_has_normals = false;

}

void ModelMesh::addVertex(struct Vertex& vertex)
{
	m_vertices.push_back(vertex);
}

void ModelMesh::addNormal(struct Normal& normal)
{
	if (!m_has_normals)
	{
		m_has_normals = true;
	}

	m_normals.push_back(normal);
}

void ModelMesh::addTextureCoordinate(struct TextureCoordinate& texcoord)
{
	if (!m_has_texcoords)
	{
		m_has_texcoords = true;
	}

	m_texcoords.push_back(texcoord);
}

void ModelMesh::addTriangle(struct Triangle& triangle)
{
	m_triangles.push_back(triangle);
}

