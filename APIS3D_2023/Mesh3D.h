#pragma once

#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "vertex_t.h"

using namespace std;

class Mesh3D
{
protected:
	static int nextMeshID; //Identificador único de malla (PISTA: Se pueden usar variables de clase estática, 
	//actualizadas cada vez que se crea un nuevo objeto Mesh3D)
	int meshID;
	glm::vec3 colorRGB; //color básico de la malla
	vector<vertex_t> vVertList; //Lista vértices que forman la malla

public:
	Mesh3D();
	int getMeshID();
	void addVertex(vertex_t vertex);
	vector<vertex_t>& getVertList();
};

