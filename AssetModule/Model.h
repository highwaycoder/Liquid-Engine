#ifndef __H_MODEL__
#define __H_MODEL__

#include <vector>

#include "Face.h"

class Model
{
	private:
		std::vector<Face> m_faces;

	public:
		Model();

		void addFace(Face&);

		void render();
};

#endif

