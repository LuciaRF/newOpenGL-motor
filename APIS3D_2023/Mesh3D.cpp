#include "Mesh3D.h"

int Mesh3D::nextMeshID = 0; //variable static se inicializa

Mesh3D::Mesh3D()
{
	this->meshID = Mesh3D::nextMeshID;
	nextMeshID++;
	colorRGB = glm::vec3(1.0f, 1.0f, 1.0f);

	//vVertList.resize(3);

	//vVertList[0].pos = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f); // izquierda
	//vVertList[1].pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);   // arriba
	//vVertList[2].pos = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);  // derecha

	vVertList = new std::vector<vertex_t>();

	vTriangleIdxList = new std::vector<unsigned int>();

	//addTriangle(0, 1, 2);

	material = nullptr;
}

int Mesh3D::getMeshID()
{
	return meshID;
}

void Mesh3D::addVertex(vertex_t vertex)
{
	vVertList->push_back(vertex);
	//vVertList.push_back(vertex);
}

vector<vertex_t>& Mesh3D::getVertList()
{
	//return vVertList;
	return *vVertList;
}

Material* Mesh3D::getMaterial()
{
	return material;
}

void Mesh3D::setMaterial(Material* mat)
{
	this->material = mat;
}

std::vector<unsigned int>* Mesh3D::getvTriangleIdxList()
{
	return vTriangleIdxList;
}

void Mesh3D::setvTriangleIdxList(std::vector<unsigned int>* vTriangleIdxList)
{
	this->vTriangleIdxList = vTriangleIdxList;
}

void Mesh3D::addTriangle(unsigned int vId1, unsigned int vId2, unsigned int vId3)
{
	vTriangleIdxList->push_back(vId1);
	vTriangleIdxList->push_back(vId2);
	vTriangleIdxList->push_back(vId3);
}
