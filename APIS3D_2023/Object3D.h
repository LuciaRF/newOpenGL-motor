#pragma once
#define GLAD_ONLY_HEADERS
#include "Object.h"
#include "pugixml.hpp"
#include "GLTexture.h"
#include "FactoryEngine.h"
class Object3D : public Object
{
public:
	//Entity

    glm::vec4 getPosition() override;
    void setPosition(glm::vec4 position) override;

    glm::vec4 getRotation() override;
    void setRotation(glm::vec4 rotation) override;

    glm::vec4 getScaling() override;
    void setScaling(glm::vec4 scaling) override;

    glm::mat4 getModelMtx() override;
    void setModelMtx(glm::mat4 modelMtx) override;

    void computeModelMatrix() override;

    void step(float deltaTime) override;

    //Object

    //Mesh3D& getMesh() override;
    //void setMesh(Mesh3D& mesh) override;

    vector<Mesh3D*>& getMeshes() override;
    void setMesh(Mesh3D& mesh) override;

    int getTipo() override;
    void setTipo(int tipo) override;

    void loadDataFromFile(const char* fileName) override;

    string extractPath(std::string filename);
};
