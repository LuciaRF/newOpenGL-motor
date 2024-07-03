#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "InputManager.h"

class GLFWInputManager : public InputManager
{
public:
	void init() override;
	bool isPressed(char key) override;
	
};

