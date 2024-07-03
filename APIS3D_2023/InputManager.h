#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include <math.h>
#include <map>

using namespace std;

class InputManager //Eventos de teclado y ratón
{
protected:
	map<int, bool> keybEvent;

public:
	virtual void init() = 0;
	virtual bool isPressed(char key) = 0;
};

