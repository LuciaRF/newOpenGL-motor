#pragma once
#define GLAD_ONLY_HEADERS
#include "Entity.h"
#include "common.h" 
#include "Mesh3D.h"
#include <string>
using namespace std;

class Object: public Entity
{
protected:
	Mesh3D mesh;
	int tipo;

public:
	virtual Mesh3D& getMesh() = 0;
	virtual void setMesh(Mesh3D& mesh) = 0;

	virtual int getTipo() = 0;
	virtual void setTipo(int tipo) = 0;

	virtual void loadDataFromFile(string file) = 0;
};

