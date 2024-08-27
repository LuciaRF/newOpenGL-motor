#include "GLFWInputManager.h"
map<int, bool> InputManager::keybEvent;

void GLFWInputManager::init()
{
    for (int i = 0; i < GLFW_KEY_LAST; i++)
    {
        keybEvent[i] = false;
    }
    GLFWwindow* window = nullptr;
    window = System::render->getWindow();
    glfwSetKeyCallback(window, keyManager);
    glfwSetCursorPosCallback(window, mouseManager);
}
bool GLFWInputManager::isPressed(char key)
{
    return keybEvent[key];
}

int GLFWInputManager::getMouseX()
{
    return mouseX;
}


int GLFWInputManager::getMouseY()
{
    return mouseY;
}


void GLFWInputManager::mouseManager(GLFWwindow* window, double xpos, double ypos)
{
    oldMouseX = mouseX;
    oldMouseY = mouseY;

    mouseX = (int)xpos;
    mouseY = (int)ypos;

    //cout << "Posición " << xpos << " " << ypos << "\n";
}

void GLFWInputManager::keyManager(GLFWwindow* window, int key, int scancode, int action, int
    mods)
{
    switch (action)
    {
    case GLFW_PRESS:
        //cout << "Tecla apretada" << endl;
        keybEvent[key] = true;
        break;
    case GLFW_RELEASE:
       // cout << "Tecla levantada" << endl;
        keybEvent[key] = false;
        break;
    }
}

