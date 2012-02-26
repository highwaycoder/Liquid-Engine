#ifndef __H_STATICMESH__
#define __H_STATICMESH__

#include "ModelMesh.h"

class StaticMesh : ModelMesh
{

	public:
		virtual bool isStatic() const { return false; }
};

#endif
