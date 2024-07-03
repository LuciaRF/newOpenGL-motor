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
    glm::vec4 getPosition();
    void setPosition(glm::vec4 position);
    
    glm::vec4 getRotation();
    void setRotation(glm::vec4 rotation);
    
    glm::vec4 getScaling();
    void setScaling(glm::vec4 scaling);

    glm::mat4 getModelMtx();
    void setModelMtx(glm::mat4 modelMtx);

    void computeModelMatrix();

    virtual void step(double deltaTime) = 0;
};

