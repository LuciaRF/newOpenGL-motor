#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Render.h"
#include "GLFWInputManager.h"
#include "System.h"
#include "GL4Render.h"
#include "GLSLMaterial.h"

using namespace std;

class FactoryEngine
{
public:

	enum GraphicsBackend {
		defaultGraphics,
		GL1,
		GL4
	};

	enum InputBackend {
		defaultInput,
		GLFW
	};

	static GraphicsBackend getSelectedGraphicsBackend();
	static void setSelectedGraphicsBackend(GraphicsBackend selectedGraphicsBackend);

	static InputBackend getSelectedInputBackend();
	static void setSelectedInputBackend(InputBackend selectedInputBackend);

	static Render* getNewRender();
	static InputManager* getNewInputManager();

	static bool isClosed();

	static Material* getNewMaterial();

	static Texture* getNewTexture();

private:
	static GraphicsBackend selectedGraphicsBackend;
	static InputBackend selectedInputBackend;
};

