#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Camera.h"
#include "System.h"

/*
Esta clase implementar� una c�mara que permitir� moverla usando eventos de teclado.
*/

class CameraKeyboard :public Camera
{
	void step(float timestep) override;
};

