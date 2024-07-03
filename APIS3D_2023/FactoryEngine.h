#pragma once
#define GLAD_ONLY_HEADERS
#include <string>
#include "common.h"
#include "GL1Render.h"
#include "GLFWInputManager.h"
using namespace std;

class FactoryEngine
{
public:

	enum GraphicsBackend {
		GL1
	};

	enum InputBackend {
		GLFW
	};

	static GraphicsBackend getSelectedGraphicsBackend();
	static void setSelectedGraphicsBackend(GraphicsBackend selectedGraphicsBackend);

	static InputBackend getSelectedInputBackend();
	static void setSelectedInputBackend(InputBackend selectedInputBackend);

	static Render* getNewRender();
	static InputManager* getNewInputManager();

	static bool isClosed();

private:
	static GraphicsBackend selectedGraphicsBackend;
	static InputBackend selectedInputBackend;
};

