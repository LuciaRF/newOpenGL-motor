#include "System.h"

Render* System::render = nullptr;
InputManager* System::inputManager = nullptr;
std::vector<Object*>* System::objects = new std::vector<Object*>();
bool System::end = false;

void System::initSystem(int width, int height)
{

	render = FactoryEngine::getNewRender(width,height);
	inputManager = FactoryEngine::getNewInputManager();

	render->init();
	inputManager->init();
}

void System::addObject(Object* obj)
{
	objects->push_back(obj);
}

void System::exit()
{
	end = true;
}

void System::mainLoop()
{
	float newTime = 0;
	float deltaTime = 0;
	float lastTime = 0;

	for (auto& obj : *objects)
	{
		render->setupObject(*obj);
	}

	while (!end)
	{
		// Limpiar buffer color y de profundidad
		//glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		newTime = static_cast<float>(glfwGetTime());
		deltaTime = newTime - lastTime;
		lastTime = newTime;
		glEnable(GL_DEPTH_TEST);

		camera->step(deltaTime);

		for (auto& obj : *objects)
		{
			obj->step(deltaTime);
			System::render->drawObjects(obj);
		}
		
		glfwSwapBuffers(System::render->getWindow()); 

		if (FactoryEngine::isClosed())
		{
			System::exit();
		}
		glfwPollEvents();
	}
	glfwTerminate();
}

glm::mat4 System::getModelMatrix()
{
	return modelMatrix;
}

void System::setModelMatrix(glm::mat4 ModelMatrix)
{
	System::modelMatrix = ModelMatrix;
}

Camera* System::getCamera()
{
	return camera;
}

void System::setCamera(Camera* cam)
{
	System::camera = cam;
}
