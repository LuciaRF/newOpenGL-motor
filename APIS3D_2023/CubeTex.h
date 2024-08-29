#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "Object3D.h"
#include "System.h"
#include "renderTypes_e.h"
#include "Mesh3D.h"

class CubeTex : public Object3D
{
public:
	CubeTex(const char* fileName);

	void step(float deltaTime) override;

	//void loadDataFromFile(const char* fileName) override;

	//template <typename T> //sirve para dividir las , de la lista de msh
	//std::vector<T> splitString(const std::string& str, char delim);
};

