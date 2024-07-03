#include "FactoryEngine.h"

FactoryEngine::GraphicsBackend FactoryEngine::selectedGraphicsBackend = FactoryEngine::GL1;
FactoryEngine::InputBackend FactoryEngine::selectedInputBackend = FactoryEngine::GLFW;

FactoryEngine::GraphicsBackend FactoryEngine::getSelectedGraphicsBackend()
{
	return selectedGraphicsBackend;
}
void FactoryEngine::setSelectedGraphicsBackend(GraphicsBackend graphicsBackend)
{
	FactoryEngine::selectedGraphicsBackend = graphicsBackend;
}

FactoryEngine::InputBackend FactoryEngine::getSelectedInputBackend()
{
	return FactoryEngine::selectedInputBackend;
}
void FactoryEngine::setSelectedInputBackend(InputBackend inputBackend)
{
	FactoryEngine::selectedInputBackend = inputBackend;
}

Render* FactoryEngine::getNewRender()
{
	int width = 640; //Esto imagino que habrá alguna forma mejor de poner los width y height
	int height = 480;
	if (FactoryEngine::selectedGraphicsBackend == GL1)
	{
		return new GL1Render(width, height);
	}
	else
	{
		throw "Backend de gráficos no soportado";
	}
}

InputManager* FactoryEngine::getNewInputManager()
{
	if (FactoryEngine::selectedInputBackend == FactoryEngine::GLFW)
	{
		return new GLFWInputManager();
	}
	else
	{
		throw "Backend de Inputs no soportado";
	}
}

bool FactoryEngine::isClosed() /*Devolverá “true” en caso de haberse cerrado la ventana
de glfw*/
{
	//!glfwWindowShouldClose(window) o glfwTerminate();
	return true;
}