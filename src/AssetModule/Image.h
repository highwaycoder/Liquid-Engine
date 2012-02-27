#ifndef __H_FACE__
#define __H_FACE__

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

class Image
{
	private:
		uint32_t m_height;
		uint32_t m_width;
		uint8_t m_bits_per_pixel;
		unsigned char* m_data;

	public:
		Image(uint32_t, uint32_t, uint8_t);
		Image(uint32_t, uint32_t, uint8_t, const unsigned char*);

		uint32_t getHeight() const { return m_height; }
		uint32_t getWidth() const { return m_width; }
		uint32_t getBPP() const { return m_bits_per_pixel; }
		const unsigned char* getData() const { return m_data; }
};

#endif

