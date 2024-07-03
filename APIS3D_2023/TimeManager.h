#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"

class TimeManager
{
public:
    float newTime;
    float deltaTime;
    float lastTime;

    void update();
};

