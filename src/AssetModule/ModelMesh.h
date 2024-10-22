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

struct Normal
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
		std::vector<struct Normal> m_normals;

		bool m_has_texcoords;
		bool m_has_normals;
	public:
		ModelMesh();
		~ModelMesh();

		virtual bool isStatic() const { return true; }

		bool hasTextureCoordinates() const { return m_has_texcoords; }
		bool hasNormals() const { return m_has_normals; }

		void addVertex(struct Vertex&);
		void addNormal(struct Normal&);
		void addTextureCoordinate(struct TextureCoordinate&);
		void addTriangle(struct Triangle&);

		const Vertex& getVertex(uint32_t index) { return m_vertices[index]; }
		const Normal& getNormal(uint32_t index) { return m_normals[index]; }
		const TextureCoordinate& getTextureCoordinate(uint32_t index) { return m_texcoords[index]; }
		const Triangle& getTriangle(uint32_t index) { return m_triangles[index]; }

		uint32_t getVertexCount() const { return m_vertices.size(); }
		uint32_t getNormalCount() const { return m_normals.size(); }
		uint32_t getTextureCoordinateCount() const { return m_texcoords.size(); }
		uint32_t getTriangleCount() const { return m_triangles.size(); }

		const std::vector<Vertex>& getVertices() const { return m_vertices; }
		const std::vector<Normal>& getNormals() const { return m_normals; }
		const std::vector<TextureCoordinate>& getTextureCoordinates() const { return m_texcoords; }
		const std::vector<Triangle>& getTriangles() const { return m_triangles; }
};

#endif
