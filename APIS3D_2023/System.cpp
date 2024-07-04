#include "System.h"

Render* System::render = nullptr;
InputManager* System::inputManager = nullptr;
std::vector<Object*>* System::objects = new std::vector<Object*>();
bool System::end = false;

void System::initSystem()
{
	FactoryEngine::setSelectedGraphicsBackend (FactoryEngine::GL1);
	FactoryEngine::setSelectedInputBackend(FactoryEngine::GLFW);

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
	float deltaTime = 0.1f;

	while (!end)
	{

		for (Object* obj : *objects)
		{
			obj->step(deltaTime);
		}
		render->drawObjects(objects);
	}
}
