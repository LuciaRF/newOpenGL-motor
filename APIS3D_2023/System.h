#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "FactoryEngine.h"

class System
{
public:
	static Render* render;
	static InputManager* inputManager;
	static std::vector<Object*>* objects; /*Puntero a una lista de objetos activos
	que se dibujar�n en pantalla.*/
	static bool end; // Variable para indicar si se debe acabar la ejecuci�n
	inline static glm::mat4 modelMatrix;

	//static glm::mat4 ModelMatrix; /* Contiene la matriz modelo del objeto que 
//se est� renderizando actualmente */


	static void initSystem();
	static void addObject(Object* obj);
	static void exit();
	static void mainLoop();

	static glm::mat4 getModelMatrix();
	static void setModelMatrix(glm::mat4 ModelMatrix);
};

