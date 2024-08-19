#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Camera.h"
#include "System.h"

/*
Esta clase implementará una cámara que permitirá moverla usando eventos de teclado.
*/

class CameraKeyboard :public Camera
{
	void step(float timestep) override;
};

