#pragma once

#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "vertex_t.h"
#include "Material.h"

using namespace std;

class Mesh3D
{
protected:
	static int nextMeshID; //Identificador único de malla (PISTA: Se pueden usar variables de clase estática, 
	//actualizadas cada vez que se crea un nuevo objeto Mesh3D)
	int meshID;
	glm::vec3 colorRGB; //color básico de la malla
	vector<vertex_t>* vVertList; //Lista vértices que forman la malla

	Material* mat;
	vector<unsigned int>* vTriangleIdxList; /*Lista de identificadores de 
vértices, cada triplete de identificadores serán un triángulo*/

public:
	Mesh3D();
	int getMeshID();
	void addVertex(vertex_t vertex);
	vector<vertex_t>& getVertList();

	Material* getMaterial();
	void setMaterial(Material * mat);
	vector<unsigned int>* getvTriangleIdxList();
	void setvTriangleIdxList(vector<unsigned int>* vTriangleIdxList);
	void addTriangle(unsigned int vId1, unsigned int vId2, unsigned int vId3);
};

