#include "Mesh3D.h"

int Mesh3D::nextMeshID = 0; //variable static se inicializa

Mesh3D::Mesh3D()
{
	this->meshID = Mesh3D::nextMeshID;
	nextMeshID++;
	colorRGB = glm::vec3(1.0f, 1.0f, 1.0f);
	vVertList = new vector<vertex_t>();
}

int Mesh3D::getMeshID()
{
	return meshID;
}

void Mesh3D::addVertex(vertex_t vertex)
{
	vVertList->push_back(vertex);
}

vector<vertex_t>* Mesh3D::getVertList()
{
	return vVertList;
}