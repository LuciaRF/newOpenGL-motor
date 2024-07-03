#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Render.h"
#include "InputManager.h"
#include "FactoryEngine.h"

class System
{
public:
	static Render* render;
	static InputManager* inputManager;
	static std::vector<Object*>* objects; /*Puntero a una lista de objetos activos
	que se dibujarán en pantalla.*/
	static bool end; // Variable para indicar si se debe acabar la ejecución

	static void initSystem();
	static void addObject(Object* obj);
	static void exit();
	static void mainLoop();
};

