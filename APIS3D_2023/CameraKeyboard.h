#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "System.h"

/*
Esta clase implementará una cámara que permitirá moverla usando eventos de teclado.
*/

class CameraKeyboard :public Camera
{
public:
	inline static double prevX = 0, prevY = 0;
	CameraKeyboard(ProjectionType type, glm::vec3 position, glm::vec3 up, glm::vec3 lookAt);

	void step(float deltaTime) override;
};

