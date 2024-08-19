#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Entity.h"

class Camera : public Entity
{
protected:
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 up;
	glm::vec3 lookAt;

private:
	Camera(glm::mat4 view, glm::mat4 projection, glm::vec3 up, glm::vec3 lookAt);

	//Camera(projection type,glm::vec3 position, glm::vec3 up, glm::vec3 lookAt); 

	glm::mat4 getProjection();
	glm::mat4 getView();
	void computeProjectionMatrix();
	void computeViewMatrix();

	virtual void step(float timestep) = 0;
};

