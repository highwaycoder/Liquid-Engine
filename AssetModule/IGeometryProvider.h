#ifndef __H_IGEOMETRYPROVIDER__
#define __H_IGEOMETRYPROVIDER__

#include <vector>

#include "GeometryType.h"

/* Forward declarations */
class Face;
class Vertex;
class TextureCoordinate;
class Normal;

class IGeometryProvider
{
	public:
		virtual std::vector<Face> const& getFaces() const = 0;

		virtual std::vector<Vertex> const& getVertices() const = 0;
		virtual std::vector<TextureCoordinate> const& getTextureCoordinates() const = 0;
		virtual std::vector<Normal> const& getNormals() const = 0;

		virtual enum GeometryType getPrimitiveType() const = 0;

};

#endif
