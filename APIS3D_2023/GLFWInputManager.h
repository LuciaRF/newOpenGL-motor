#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "InputManager.h"
#include "System.h"

class GLFWInputManager : public InputManager
{
public:
	
	static void keyManager(GLFWwindow* window, int key, int scancode, int action, int
		mods);

	void init() override;
	bool isPressed(char key) override;
};

