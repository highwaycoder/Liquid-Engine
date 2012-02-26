#ifndef __H_MODELMESH__
#define __H_MODELMESH__

#include <stdint.h>
#include <vector>

struct Vertex
{
	float x;
	float y;
	float z;
};

struct TextureCoordinate
{
	float u;
	float v;
};

struct Triangle
{
	uint32_t indices[3];
};

class ModelMesh
{
	private:
		std::vector<struct Vertex> m_vertices;
		std::vector<struct TextureCoordinate> m_texcoords;
		std::vector<struct Triangle> m_triangles;
		//std::vector<struct Triangle> m_normals;

		bool m_has_texcoords;
		bool m_has_normals;
	public:
		ModelMesh();
		~ModelMesh();

		virtual bool isStatic() const { return true; }
		bool hasTextureCoordinates() const { return m_has_texcoords; }

		void addVertex(struct Vertex&);
		void addTextureCoordinate(struct TextureCoordinate&);
		void addTriangle(struct Triangle&);

		const Vertex& getVertex(uint32_t index) { return m_vertices[index]; }
		const Triangle& getTriangle(uint32_t index) { return m_triangles[index]; }

		uint32_t getVertexCount() const { return m_vertices.size(); }
		int32_t getTriangleCount() const { return m_triangles.size(); }
};

#endif
