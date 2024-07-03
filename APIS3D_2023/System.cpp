#include "System.h"
#include "TimeManager.h"

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
	TimeManager t;

	while (!end)
	{
		t.update();

		for (Object* obj : *objects)
		{
			obj->step(t.deltaTime);
		}
		render->drawObjects(objects);
	}
}
