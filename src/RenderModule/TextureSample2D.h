#ifndef __H_TEXTURESAMPLE2D__
#define __H_TEXTURESAMPLE2D__

#include <stdint.h>

class Image;

class TextureSample2D
{
	private:
		uint32_t m_gltexture_handle;

	public:
		TextureSample2D(Image&);
		~TextureSample2D();

		void useTexture();
};

#endif
