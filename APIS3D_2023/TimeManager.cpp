#include "TimeManager.h"

void TimeManager::update()
{
    TimeManager::newTime = static_cast<float>(glfwGetTime());
    TimeManager::deltaTime = TimeManager::newTime - TimeManager::lastTime;
    TimeManager::lastTime = TimeManager::newTime;
}