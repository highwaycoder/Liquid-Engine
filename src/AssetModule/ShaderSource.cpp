#include "ShaderSource.h"

#include <stdlib.h>
#include <stdio.h>

ShaderSource::ShaderSource(const char* path)
{
	load(path);
}

ShaderSource::~ShaderSource()
{
	free(m_data);
}

void ShaderSource::load(const char* path)
{
	FILE* file;
	int file_size = -1;

	/* Open the model file */
	file = fopen(path, "rb");

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file into memory */
	m_data = (char*)(malloc(sizeof(char) * (file_size + 1))); /* Adding 1 byte for null-term purposes */
	fread(m_data, sizeof(char), file_size, file);

	/* Null terminate the string */
	m_data[file_size] = '\0';

	/* We no longer need this file open */
	fclose(file);
}

void ShaderSource::print()
{
	printf("////////////////\n");

	printf("%s\n", m_data);

	printf("////////////////\n");
}
