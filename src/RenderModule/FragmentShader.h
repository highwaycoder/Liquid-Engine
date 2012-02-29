#ifndef __H_FRAGMENTSHADER__
#define __H_FRAGMENTSHADER__

#include "Shader.h"

#include <stdint.h>

class ShaderSource;

class FragmentShader : public Shader
{
	public:
		FragmentShader(ShaderSource*);
		~FragmentShader();
};

#endif
