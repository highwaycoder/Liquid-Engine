#ifndef __H_MODELLOADER__
#define __H_MODELLOADER__

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <cstring>

#include "Vertex.h"
#include "Face.h"
#include "Model.h"

Model loadObj(const char* path);

int count_lines(const char* text);
int count_words(const char* text);
char** read_lines(const char* text);
char** read_words(const char* text);
int count_token_occurence(const char*, const char*);
int number_from_char(char);

#endif
