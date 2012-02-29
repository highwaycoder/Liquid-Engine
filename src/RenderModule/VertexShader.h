#ifndef __H_VERTEXSHADER__
#define __H_VERTEXSHADER__

#include "Shader.h"

#include <stdint.h>

class ShaderSource;

class VertexShader : public Shader
{
	public:
		VertexShader(ShaderSource*);
		~VertexShader();
};

#endif
