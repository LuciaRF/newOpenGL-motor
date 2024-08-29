#pragma once
#define GLAD_ONLY_HEADERS
#include "Entity.h"
#include "common.h" 
#include "Mesh3D.h"

using namespace std;

class Object: public Entity
{
protected:
	//Mesh3D mesh;
	std::vector<Mesh3D*> meshes;
	int tipo;

public:
	//virtual Mesh3D& getMesh() = 0;
	//virtual void setMesh(Mesh3D& mesh) = 0;
	
	virtual vector<Mesh3D*>& getMeshes() = 0;
	virtual void setMesh(Mesh3D& mesh) = 0;

	virtual int getTipo() = 0;
	virtual void setTipo(int tipo) = 0;

	virtual void loadDataFromFile(const char* fileName) = 0;
};

