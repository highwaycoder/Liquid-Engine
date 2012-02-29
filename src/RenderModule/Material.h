#ifndef __H_MATERIAL__
#define __H_MATERIAL__

#include "Shader.h"

#include <stdint.h>

class Material
{
	protected:
		uint32_t m_program_id; /* Used internally by opengl to keep track of shader program */		

	public:
		Material();
		~Material();

		void AttachShader(Shader*);
		void DetachShader(Shader*);

		void LinkMaterial();

		void UseMaterial();

		uint32_t getProgramID() const { return m_program_id; }
};

#endif
