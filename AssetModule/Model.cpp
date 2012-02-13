#include "Model.h"

Model::Model()
{

}


void Model::addFace(Face& face)
{
	m_faces.push_back(face);
}

std::vector<Face> Model::getFaces() const
{
	std::vector<Face> faces(m_faces);

	return faces;
}

