#ifndef __H_MODEL__
#define __H_MODEL__

#include <vector>
#include <stdint.h>

#include "GeometryType.h"
#include "IGeometryProvider.h"

/* Forward declarations */
class Face;
class Vertex;
class TextureCoordinate;
class Normal;

class Model : IGeometryProvider
{
	private:
		std::vector<Face> m_faces;

		std::vector<Vertex> m_vertices;
		std::vector<TextureCoordinate> m_texture_coordinates;
		std::vector<Normal> m_normals;
	public:
		Model();

		void addFace(Face&);

		void addVertex(Vertex&);
		void addTextureCoordinate(TextureCoordinate&);
		void addNormal(Normal&);

		bool isValid() const;


		virtual enum GeometryType getPrimitiveType() const;

		virtual std::vector<Face> const& getFaces() const;

		virtual std::vector<Vertex> const& getVertices() const;
		virtual std::vector<TextureCoordinate> const& getTextureCoordinates() const;
		virtual std::vector<Normal> const& getNormals() const;
};

#endif

