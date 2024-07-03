#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "Object.h"

using namespace std;

class Render
{
protected:
	int width;
	int height;
public:
	virtual int getWidth() = 0;
	virtual void setWidth(int width) = 0;
	virtual int getHeight() = 0;
	virtual void setHeight(int height) = 0;

	virtual void init() = 0;
	virtual void setupObject(Object* obj) = 0;
	virtual void removeObject(Object* obj) = 0;
	virtual void drawObjects(std::vector<Object*>* objs) = 0; // OJO: Estos objetos
	//deben haberse inicializado antes usando el método “setupObject”
	virtual bool isClosed() = 0;
};

