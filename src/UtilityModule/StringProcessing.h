#ifndef __H_STRINGPROCESSING__
#define __H_STRINGPROCESSING__

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <cstring>

int count_lines(const char* text);
int count_words(const char* text);
char** read_lines(const char* text);
char** read_words(const char* text);
int count_token_occurence(const char*, const char*);
void replace_character(char*, char, char);
#endif
