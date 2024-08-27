#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "FactoryEngine.h"
#include "Camera.h"

class System
{
public:
	static Render* render;
	static InputManager* inputManager;
	static std::vector<Object*>* objects; /*Puntero a una lista de objetos activos
	que se dibujarán en pantalla.*/
	static bool end; // Variable para indicar si se debe acabar la ejecución

	inline static Camera* camera;

	inline static glm::mat4 modelMatrix;

	static void initSystem(int width, int height);
	static void addObject(Object* obj);
	static void exit();
	static void mainLoop();
	
	static Camera* getCamera();
	static void setCamera(Camera* cam);

	static glm::mat4 getModelMatrix();
	static void setModelMatrix(glm::mat4 ModelMatrix);

};

