#include "Model.h"

Model::Model()
{

}


void Model::addFace(Face& face)
{
	m_faces.push_back(face);
}

void Model::render()
{
	for (int index = 0; index < m_faces.size(); index++)
	{
		m_faces[index].render();

	}
}
