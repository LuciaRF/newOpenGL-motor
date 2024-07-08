#include "GLFWInputManager.h"
map<int, bool> InputManager::keybEvent;

void GLFWInputManager::init()
{
    for (int i = 0; i < GLFW_KEY_LAST; i++)
    {
        keybEvent[i] = false;
    }
    GLFWwindow* window = System::render->getWindow();
    glfwSetKeyCallback(window, keyManager);
}
bool GLFWInputManager::isPressed(char key)
{
    //std::cout << "Entra en isPressed: "<< keybEvent[key] << endl;
    return keybEvent[key];
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

