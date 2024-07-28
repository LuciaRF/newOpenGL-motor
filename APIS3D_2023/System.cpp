#include "System.h"

Render* System::render = nullptr;
InputManager* System::inputManager = nullptr;
std::vector<Object*>* System::objects = new std::vector<Object*>();
bool System::end = false;

void System::initSystem()
{
	render = FactoryEngine::getNewRender();
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
	newTime = static_cast<float>(glfwGetTime());
	deltaTime = newTime - lastTime;
	lastTime = newTime;

	while (!end)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		for (auto& obj : *objects)
		{
			System::setModelMatrix(obj->getModelMtx());
			obj->step(deltaTime);
			System::render->drawObjects(objects);
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

void System::setModelMatrix(glm::mat4 Matrix)
{
	System::modelMatrix = Matrix;
}
