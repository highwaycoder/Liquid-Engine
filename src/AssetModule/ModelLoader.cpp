#include "ModelMesh.h"

#include <assimp/assimp.hpp>      // C++ importer interface
#include <assimp/aiScene.h>       // Output data structure
#include <assimp/aiMesh.h>
#include <assimp/aiPostProcess.h>

#include <stdio.h>

ModelMesh* loadModel(char* path)
{
	printf("meep\n");

	ModelMesh* mesh = new ModelMesh();

	Assimp::Importer importer;
	const aiScene* scene = (aiScene*) importer.ReadFile(path, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_CalcTangentSpace | aiProcess_GenNormals);

	/* We don't have any meshes, so scrap this file */
	if (!scene->HasMeshes())
	{
		return NULL;
	}

	/* Start creating meshes from the model */
	for (uint32_t mesh_index = 0; mesh_index < scene->mNumMeshes; mesh_index++)
	{
		printf("Model Mesh: %i\n", mesh_index);

		aiMesh* aimesh = scene->mMeshes[mesh_index];

		uint32_t num_vertices = aimesh->mNumVertices;
		uint32_t num_normals = aimesh->mNumVertices;
		uint32_t num_triangles = aimesh->mNumFaces;
		uint32_t num_texcoords = aimesh->mNumVertices;

		/* Store vertices (and if they exist: Normals!) */
		for (uint32_t vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			struct Vertex vertex;
			vertex.x = aimesh->mVertices[vertex_index].x;
			vertex.y = aimesh->mVertices[vertex_index].y;
			vertex.z = aimesh->mVertices[vertex_index].z;

			if (aimesh->HasNormals())
			{
				struct Normal normal;
				normal.x = aimesh->mNormals[vertex_index].x;
				normal.y = aimesh->mNormals[vertex_index].y;
				normal.z = aimesh->mNormals[vertex_index].z;

				mesh->addNormal(normal);
			}

			mesh->addVertex(vertex);
		}

		/* Store texture coordinates */
		for (uint32_t texcoord_index = 0; texcoord_index < num_texcoords; texcoord_index++)
		{
			struct TextureCoordinate texcoord;

			if (aimesh->HasTextureCoords(0))
			{
				texcoord.u = aimesh->mTextureCoords[0][texcoord_index].x;
				texcoord.v = aimesh->mTextureCoords[0][texcoord_index].y;

				printf("%u (%f, %f)\n", texcoord_index, texcoord.u, texcoord.v);
				mesh->addTextureCoordinate(texcoord);
			}
		}

		/* Store triangles (assumes: faces are triangulated) */
		for (uint32_t face_index = 0; face_index < num_triangles; face_index++)
		{
			struct Triangle triangle;
			triangle.indices[0] = aimesh->mFaces[face_index].mIndices[0];
			triangle.indices[1] = aimesh->mFaces[face_index].mIndices[1];
			triangle.indices[2] = aimesh->mFaces[face_index].mIndices[2];

			mesh->addTriangle(triangle);
		}

	}

	return mesh;
}
