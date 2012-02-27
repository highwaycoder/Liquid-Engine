#include "Image.h"

Image::Image(uint32_t height, uint32_t width, uint8_t bits_per_pixel)
{
	uint8_t bytes_per_pixel = bits_per_pixel / 8;
	uint64_t data_size = width * height * bytes_per_pixel;

	m_height = height;
	m_width = width;
	m_bits_per_pixel = bits_per_pixel;

	m_data = (unsigned char*)malloc(sizeof(char) * data_size);

	memset(m_data, 0, data_size);
}

Image::Image(uint32_t height, uint32_t width, uint8_t bits_per_pixel, const unsigned char* data)
{
	uint8_t bytes_per_pixel = bits_per_pixel / 8;
	uint64_t data_size = width * height * bytes_per_pixel;

	m_height = height;
	m_width = width;
	m_bits_per_pixel = bits_per_pixel;

	m_data = (unsigned char*)malloc(sizeof(char) * data_size);

	memcpy(m_data, data, data_size);
}
