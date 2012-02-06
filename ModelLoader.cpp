#include "ModelLoader.h"

Model loadObj(const char* path)
{
	FILE* file;
	int file_size = -1;
	char* file_memory = NULL;

	char** lines = NULL;
	int line_count = 0;

	std::vector<Vertex> vertices;
	std::vector<Vertex> texture_coordinates;
	std::vector<Vertex> normals;

	/* Open the model file */
	file = fopen(path, "r");

	/* Create a model */
	Model model;

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

	/* Let's get a list and count of our lines */
	lines = read_lines(file_memory);
	line_count = count_lines(file_memory);

	/* Free our file memory */
	free(file_memory);

	/* Process each of our lines */
	for (int index = 0; index < line_count; index++)
	{	
		char** words = read_words(lines[index]);
		char* operator_token = words[0];
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

			printf("Vertex: %f %f %f\n", x, y, z);

			Vertex vertex(x, y, z);

			/* Store it (these should stay in order, linearly - THIS IS CRUCIAL) */
			vertices.push_back(vertex);
		}
		else if (strcmp(operator_token, "vt") == 0)
		{
			/* Parse vertex */
			float x = atof(words[1]);
			float y = atof(words[2]);
			float z = 0;

			printf("Texture Coordinate: %f %f %f\n", x, y, z);

			Vertex vertex(x, y, z);

			/* Store it (these should stay in order, linearly - THIS IS CRUCIAL) */
			texture_coordinates.push_back(vertex);
		}
		else if (strcmp(operator_token, "vn") == 0)
		{
			/* Parse vertex */
			float x = atof(words[1]);
			float y = atof(words[2]);
			float z = atof(words[3]);

			printf("Normal: %f %f %f\n", x, y, z);

			Vertex vertex(x, y, z);

			/* Store it (these should stay in order, linearly - THIS IS CRUCIAL) */
			normals.push_back(vertex);
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

					/* The OBJ indexes are not zero-indexed */
					vertex_index = vertex_index - 1;

					face.addVertex(vertices[vertex_index]);
				}
				/* Handle vertex & tex coord scenario: v1/vt1 */
				else if (double_slash_count == 0 && single_slash_count == 1)
				{
					vertex_index = atoi(strtok(definition_copy, "/"));
					texture_coord_index = atoi(strtok(NULL, "/"));

					/* The OBJ indexes are not zero-indexed */
					vertex_index = vertex_index - 1;
					texture_coord_index = texture_coord_index -1;

					face.addVertex(vertices[vertex_index]);
					face.addTextureCoordinate(texture_coordinates[texture_coord_index]);
				}
				/* Handle vertex, tex coord, and normal scenario: v1/vt1/vn1 */
				else if (double_slash_count == 0 && single_slash_count == 2)
				{
					vertex_index = atoi(strtok(definition_copy, "/"));
					texture_coord_index = atoi(strtok(NULL, "/"));
					normal_index = atoi(strtok(NULL, "/"));

					/* The OBJ indexes are not zero-indexed */
					vertex_index = vertex_index - 1;
					texture_coord_index = texture_coord_index -1;
					normal_index = normal_index - 1;

					face.addVertex(vertices[vertex_index-1]);
					face.addTextureCoordinate(texture_coordinates[texture_coord_index]);
					face.addNormal(normals[normal_index]);
				}
				/* Handle vertex & normal scenario: v1//vn1 */
				else if (double_slash_count == 2 && single_slash_count == 2)
				{
					vertex_index = atoi(strtok(definition_copy, "//"));
					normal_index = atoi(strtok(NULL, "//"));

					/* The OBJ indexes are not zero-indexed */
					vertex_index = vertex_index - 1;
					normal_index = normal_index - 1;

					face.addVertex(vertices[vertex_index]);
					face.addNormal(normals[normal_index]);
				}


				/* Free the copy of the definition */
				free(definition_copy);
			}

			/* Add face to the model */
			model.addFace(face);
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

	return model;
}

int count_lines(const char* source_text)
{
	int line_count = 0;
	int string_length = strlen(source_text);
	char* string_copy = NULL;
	char* current_line = NULL;

	/* Give us a working copy of the original string */
	string_copy = (char*)(malloc(sizeof(char) * (string_length + 1)));
	strncpy(string_copy, source_text, string_length);

	/* Null terminate this string */
	string_copy[string_length] = (char)'\0';

	/* Tokenize and count lines */
	current_line = strtok(string_copy, "\n");

	while(current_line != NULL)
	{
		line_count++;

		current_line = strtok(NULL, "\n");
	}

	/* Free our string copy */
	free(string_copy);

	/* Give us the count */
	return line_count;
}

int count_words(const char* source_text)
{
	int word_count = 0;
	int string_length = strlen(source_text);
	char* string_copy = NULL;
	char* current_word = NULL;

	/* Give us a working copy of the original string */
	string_copy = (char*)(malloc(sizeof(char) * (string_length + 1)));
	strncpy(string_copy, source_text, string_length);

	/* Null-terminate this string */
	string_copy[string_length] = (char)'\0';

	/* Tokenize and count lines */
	current_word = strtok(string_copy, " ");

	while(current_word != NULL)
	{
		word_count++;

		current_word = strtok(NULL, " ");
	}

	/* Free our string copy */
	free(string_copy);

	/* Give us the count */
	return word_count;
}

char** read_lines(const char* source_text)
{
	int line_count = count_lines(source_text);
	int line_number = 0;
	int string_length = strlen(source_text);
	char* string_copy = NULL;
	char* current_line = NULL;
	char** lines = NULL;

	/* Allocate an array of n string pointers */
	lines = (char**)(malloc(sizeof(char*) * line_count));

	/* Give us a working copy of the original string */
	string_copy = (char*)(malloc(sizeof(char) * (string_length + 1)));
	strcpy(string_copy, source_text);

	/* Null-terminate this string */
	string_copy[string_length] = (char)'\0';

	/* Tokenize and store lines */
	current_line = strtok(string_copy, "\n");

	while(current_line != NULL)
	{
		int line_length = strlen(current_line);

		lines[line_number] = (char*)(malloc(sizeof(char) * (line_length + 1)));

		strncpy(lines[line_number], current_line, line_length); 

		/* Null-terminate */
		lines[line_number][line_length] = (char)'\0';

		line_number++;

		current_line = strtok(NULL, "\n");		
	}

	/* Free our string copy */
	free(string_copy);

	/* Give us the lines */
	return lines;
}

char** read_words(const char* source_text)
{
	int word_count = count_words(source_text);
	int word_number = 0;
	int string_length = strlen(source_text);
	char* string_copy = NULL;
	char* current_word = NULL;
	char** words = NULL;

	/* Allocate an array of n string pointers */
	words = (char**)(malloc(sizeof(char*) * word_count));

	/* Give us a working copy of the original string */
	string_copy = (char*)(malloc(sizeof(char) * (string_length + 1)));
	strncpy(string_copy, source_text, string_length);

	/* Null-terminate this string */
	string_copy[string_length] = (char)'\0';
	
	/* Tokenize and store words */
	current_word = strtok(string_copy, " ");

	while(current_word != NULL)
	{
		int word_length = strlen(current_word);

		words[word_number] = (char*)(malloc(sizeof(char) * (word_length + 1)));

		strncpy(words[word_number], current_word, word_length); 

		/* Null-terminate */
		words[word_number][word_length] = (char)'\0';

		word_number++;

		current_word = strtok(NULL, " ");		
	}

	/* Free our string copy */
	free(string_copy);

	/* Give us the words */
	return words;
}

int count_token_occurence(const char* source_text, const char* token)
{
	int source_string_length = strlen(source_text);
	int token_string_length = strlen(token);
	int token_count = 0;
	char* comparison_string = (char*)(malloc(sizeof(char) * (token_string_length + 1))); //this is used so we've got a place to store comparison substrings


	for (int index = 0; index < (source_string_length - token_string_length + 1); index++)
	{
		/* Copy a string equivalent to the length of the search token from the source string */
		char* substring_pointer = (char*)(source_text + index);
		strncpy(comparison_string, substring_pointer, token_string_length);

		/* Null-terminate the string */
		comparison_string[token_string_length] = (char)'\0';


		/* Iterate count, because we've found one */
		if (strcmp(token, comparison_string) == 0)
		{
			token_count++;
		}
	}

	/* Free our string copy */
	free(comparison_string);

	/* Return the token count */
	return token_count;
}

int number_from_char(char character)
{
	int char_value = (int)character; //I need the ascii value
	
	if (char_value >= 48 && char_value <= 57)
		return (char_value - 48);
	else
		return -1; //Invalid number passed
}
