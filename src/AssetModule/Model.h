#ifndef __H_MODEL__
#define __H_MODEL__

#include "stdint.h"

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
	uint16_t vertex_index[3];
	uint16_t texcoord_index[3];
};

class Model
{
	public:
		Model();
		~Model();
};

#endif

