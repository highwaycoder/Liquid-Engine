#include "ObjLoader.h"

#include "UtilityModule/StringProcessing.h"

Model* loadObj(const char* path)
{
	FILE* file;
	int file_size = -1;
	char* file_memory = NULL;

	char** lines = NULL;
	int line_count = 0;

	/* Open the model file */
	file = fopen(path, "r");

	/* Create a model */
	Model* model = new Model;

	/* Assess file size */
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	/* Read the file into memory */
	file_memory = (char*)(malloc(sizeof(char) * (file_size + 1)));
	fread(file_memory, sizeof(char), file_size, file);

	/* We no longer need this file open */
	fclose(file);

	/* Null-terminate the file string */
	file_memory[file_size] = (char)'\0';

	/* Because fuck carriage returns */
	replace_character(file_memory, '\r', ' ');

	/* Let's get a list and count of our lines */
	lines = read_lines(file_memory);
	line_count = count_lines(file_memory);

	/* Free our file memory */
	free(file_memory);

	/* Process each of our lines */
	for (int index = 0; index < line_count; index++)
	{	
		char** words = read_words(lines[index]);
		const char* operator_token = words[0];
		int word_count = count_words(lines[index]);

		if (operator_token[0] == '#')
		{
			/* Do Nothing */
		}
		else if (strcmp(operator_token, "v") == 0)
		{
			/* Parse vertex */
			float x = atof(words[1]);
			float y = atof(words[2]);
			float z = atof(words[3]);

			Vertex vertex(x, y, z);

			/* Store it (these should stay in order, linearly - THIS IS CRUCIAL) */
			model->addVertex(vertex);
		}
		else if (strcmp(operator_token, "vt") == 0)
		{
			/* Parse vertex */
			float u = atof(words[1]);
			float v = atof(words[2]);
			float w = 0;

			/* Check for the optional coordinate */
			if (words[3] != NULL)
				w = atof(words[3]);

			TextureCoordinate textureCoordinate(u, v, w);

			/* Store it (these should stay in order, linearly - THIS IS CRUCIAL) */
			model->addTextureCoordinate(textureCoordinate);
		}
		else if (strcmp(operator_token, "vn") == 0)
		{
			/* Parse vertex */
			float x = atof(words[1]);
			float y = atof(words[2]);
			float z = atof(words[3]);

			Normal normal(x, y, z);

			/* Store it (these should stay in order, linearly - THIS IS CRUCIAL) */
			model->addNormal(normal);
		}
		else if (strcmp(operator_token, "f") == 0)
		{
			/* Create a working face */
			Face face;

			/* Parse each face vertex/[texture coord]/[[normal]] */
			for (int face_definition_index = 1; face_definition_index < word_count; face_definition_index++)
			{
				int vertex_index = -1;
				int texture_coord_index = -1;
				int normal_index = -1;
				int double_slash_count = count_token_occurence(words[face_definition_index], "//");
				int single_slash_count = count_token_occurence(words[face_definition_index], "/");
				int string_length = strlen(words[face_definition_index]);
				char* definition_copy = NULL;

				/* Give us a working copy of the original string */
				definition_copy = (char*)(malloc(sizeof(char) * (string_length + 1)));
				strncpy(definition_copy, words[face_definition_index], string_length);

				/* Null terminate this string */
				definition_copy[string_length] = (char)'\0';

				/* Handle sole vertex  scenario: v1 */
				if (double_slash_count == 0 && single_slash_count == 0)
				{
					vertex_index = atoi(words[face_definition_index]);

					face.addVertex(vertex_index - 1);
				}
				/* Handle vertex & tex coord scenario: v1/vt1 */
				else if (double_slash_count == 0 && single_slash_count == 1)
				{
					vertex_index = atoi(strtok(definition_copy, "/"));
					texture_coord_index = atoi(strtok(NULL, "/"));

					face.addVertex(vertex_index - 1);
					face.addTextureCoordinate(texture_coord_index - 1);
				}
				/* Handle vertex, tex coord, and normal scenario: v1/vt1/vn1 */
				else if (double_slash_count == 0 && single_slash_count == 2)
				{
					vertex_index = atoi(strtok(definition_copy, "/"));
					texture_coord_index = atoi(strtok(NULL, "/"));
					normal_index = atoi(strtok(NULL, "/"));

					face.addVertex(vertex_index - 1);
					face.addTextureCoordinate(texture_coord_index - 1);
					face.addNormal(normal_index - 1);
				}
				/* Handle vertex & normal scenario: v1//vn1 */
				else if (double_slash_count == 2 && single_slash_count == 2)
				{
					vertex_index = atoi(strtok(definition_copy, "//"));
					normal_index = atoi(strtok(NULL, "//"));

					face.addVertex(vertex_index - 1);
					face.addNormal(normal_index - 1);
				}

				/* Free the copy of the definition */
				free(definition_copy);
			}

			/* Add face to the model */
			model->addFace(face);
		}

		/* Free word memory */
		for (int word_index = 0; word_index < word_count; word_index++)
		{
			free(words[word_index]);
		}
		free(words);
	}

	/* Free line memory */
	for (int line_index = 0; line_index < line_count; line_index++)
	{
		free(lines[line_index]);
	}
	free(lines);


	/* Check model validity */
	if (model->isValid())
	{
		return model; /* valid model, return it */
	}
	else
	{
		delete model; /* Free the model */
		return NULL;
	}
}

