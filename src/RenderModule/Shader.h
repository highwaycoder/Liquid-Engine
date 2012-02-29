#ifndef __H_SHADER__
#define __H_SHADER__

#include <stdint.h>

class Shader
{
	protected:
		uint32_t m_shader_id;		

	public:
		Shader();

		uint32_t getShaderID() const { return m_shader_id; }
};

#endif
