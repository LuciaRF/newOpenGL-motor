#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "GL1Render.h"
#include <math.h>
#include <map>

using namespace std;

class InputManager //: public GL1Render //Eventos de teclado y rat�n
{
protected:
	map<int, bool> keybEvent;

public:
	virtual void init() = 0;
	virtual bool isPressed(char key) = 0;
};

