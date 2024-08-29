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

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(window, 0.0, 0.0);
}
bool GLFWInputManager::isPressed(char key)
{
    return keybEvent[key];
}

//int GLFWInputManager::getMouseX()
//{
//    return mouseX;
//}
//
//
//int GLFWInputManager::getMouseY()
//{
//    return mouseY;
//}


void GLFWInputManager::mouseManager(GLFWwindow* window, double xpos, double ypos)
{
    oldPosX = posX;
    oldPosY = posY;
    posX = (int)xpos;
    posY = (int)ypos;

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

