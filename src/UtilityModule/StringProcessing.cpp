#include "StringProcessing.h"

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

//Feb-6-2012 found a bug, ending a line in a space gives a false token count
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

void replace_character(char* string_to_modify, char target, char replacement)
{
	int string_length = strlen(string_to_modify);

	for (int index = 0; index < string_length; index++)
	{
		if (string_to_modify[index] == target)
			string_to_modify[index] = replacement;
	}
}

