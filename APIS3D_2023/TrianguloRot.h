#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "Object3D.h"
#include "System.h"
#include "renderTypes_e.h"
#include "GLSLMaterial.h"

class TrianguloRot : public Object3D
{
public:
	TrianguloRot();

	void step(double deltaTime) override;
};

