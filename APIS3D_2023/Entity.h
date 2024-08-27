#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 

class Entity
{
protected:
    glm::vec4 position;
    glm::vec4 rotation;
    glm::vec4 scaling;

    glm::mat4 modelMtx;

public:
    virtual glm::vec4 getPosition() = 0;
    virtual void setPosition(glm::vec4 position) = 0;
    
    virtual glm::vec4 getRotation() = 0;
    virtual void setRotation(glm::vec4 rotation) = 0;
    
    virtual glm::vec4 getScaling() = 0;
    virtual void setScaling(glm::vec4 scaling) = 0;

    virtual glm::mat4 getModelMtx() = 0;
    virtual void setModelMtx(glm::mat4 modelMtx) = 0;

    virtual void computeModelMatrix() = 0;

    virtual void step(float deltaTime) = 0;
};

