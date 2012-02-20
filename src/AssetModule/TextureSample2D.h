#ifndef __H_FACE__
#define __H_FACE__

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

class TextureSample2D
{
	private:
		uint32_t m_height;
		uint32_t m_width;
		uint8_t m_bits_per_pixel;
		unsigned char* m_data;

	public:
		TextureSample2D(uint32_t, uint32_t, uint8_t);
		TextureSample2D(uint32_t, uint32_t, uint8_t, unsigned char*);
};

#endif

