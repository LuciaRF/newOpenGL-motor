#include "GLFWInputManager.h"


//void GLFWInputManager::keyManager(GLFWwindow* window, int key, int scancode, int action, int
//    mods)
//{
//    switch (action)
//    {
//    case GLFW_PRESS:
//        cout << "Tecla apretada" << endl;
//        keybEvent[key] = true;
//        break;
//    case GLFW_RELEASE:
//        cout << "Tecla levantada" << endl;
//        keybEvent[key] = false;
//        break;
//    }
//}

void GLFWInputManager::init()
{
    for (int i = 0; i < GLFW_KEY_LAST; i++)
    {
        keybEvent[i] = false;
    }
   // glfwSetKeyCallback(window, keyManager);   
}
bool GLFWInputManager::isPressed(char key)
{
    return true;
}

