#include "FactoryEngine.h"

FactoryEngine::GraphicsBackend FactoryEngine::selectedGraphicsBackend = FactoryEngine::defaultGraphics;
FactoryEngine::InputBackend FactoryEngine::selectedInputBackend = FactoryEngine::defaultInput;

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

Render* FactoryEngine::getNewRender(int width, int height)
{
	//int width = 640; //Esto imagino que habrá alguna forma mejor de poner los width y height
	//int height = 480;
	if (FactoryEngine::selectedGraphicsBackend == FactoryEngine::GL1)
	{
		return new GL1Render(width, height);
	}
	else if (FactoryEngine::selectedGraphicsBackend == FactoryEngine::GL4)
	{
		return new GL4Render(width, height);
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

	return (System::render)->isClosed();
	
}

Material* FactoryEngine::getNewMaterial()
{
	if (FactoryEngine::selectedGraphicsBackend == FactoryEngine::GL4)
	{
		return new GLSLMaterial();
	}
	else
	{
		throw "No seleccionado GL4";
	}
}

Texture* FactoryEngine::getNewTexture(const char* fileName)
{
	if (FactoryEngine::selectedGraphicsBackend == FactoryEngine::GL1  || 
		FactoryEngine::selectedGraphicsBackend == FactoryEngine::GL4)
	{
		return new GLTexture(fileName);
	}
	else
	{
		throw "No seleccionado GL1-GL4";
	}
}
