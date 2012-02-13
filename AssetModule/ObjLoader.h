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

#endif
