#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"

using namespace std;

class InputManager
{
public:
	virtual void init() = 0;
	virtual bool isPressed(char key) = 0;

protected:
	static map<int, bool> keybEvent;
};

