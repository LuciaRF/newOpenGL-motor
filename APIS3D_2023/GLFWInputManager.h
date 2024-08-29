#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "InputManager.h"
#include "System.h"

class GLFWInputManager : public InputManager
{
public:
	//inline static int mouseX, mouseY;
	//inline static int oldMouseX, oldMouseY;

	inline static int posX = 0, posY = 0;
	inline static int oldPosX = 0, oldPosY = 0;

	//static int getMouseX();
	//static int getMouseY();
	static void mouseManager(GLFWwindow* window, double xpos, double ypos);

	static void keyManager(GLFWwindow* window, int key, int scancode, int action, int
		mods);

	void init() override;
	bool isPressed(char key) override;
};

