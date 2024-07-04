#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "Object3D.h"
class TrianguloRot : public Object3D
{
public:
	TrianguloRot();

	void step(double deltaTime) override;
};

