#pragma once
#define GLAD_ONLY_HEADERS
#include "Entity.h"
#include "common.h" 
#include "Mesh3D.h"
#include <string>
using namespace std;

class Object: public Entity
{
	Mesh3D* mesh;
	int tipo;

public:
	Mesh3D* getMesh();
	void setMesh(Mesh3D* mesh);

	int getTipo();
	void setTipo(int tipo);

	virtual void loadDataFromFile(string file) = 0;
};

