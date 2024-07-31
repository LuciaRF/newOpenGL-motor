#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "Object3D.h"
#include "System.h"
#include "renderTypes_e.h"
#include "Mesh3D.h"

class TrianguloRot : public Object3D
{
public:
	//TrianguloRot* triangulo = new TrianguloRot();
	TrianguloRot();

	void step(double deltaTime) override;
};

