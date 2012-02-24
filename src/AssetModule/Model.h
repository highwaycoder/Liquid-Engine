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
	uint32_t vertex_index[3];
	uint32_t texcoord_index[3];
};

struct Frame
{
	char name[64];
	struct Vertex* vertices;
};

class Model
{
	public:
		Model();
		~Model();
};

#endif

