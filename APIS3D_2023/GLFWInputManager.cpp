#include "GLFWInputManager.h"

void GLFWInputManager::init()
{
	int posX, posY;
	int oldPosX, oldPosY;

    for (int i = 0; i < GLFW_KEY_LAST; i++)
    {
        keybEvent[i] = false;
    }
    posX = posY = oldPosX = oldPosY = 0;

}

bool GLFWInputManager::isPressed(char key)
{
    //comprobar si hay alguna funci�n que permita saber si la tecla est� seleccionada
    return true;
}

