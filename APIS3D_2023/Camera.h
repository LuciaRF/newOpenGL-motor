#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Entity.h"
//#include "System.h"

class Camera : public Entity
{
public:

	enum class ProjectionType {
		Perspective,
		Orthographic
	};

	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 up;
	glm::vec3 lookAt;

	float angle = 90.0f; //angulo de apertura
	/* Este ángulo define cuánto del mundo 3D es visible en la pantalla. Un FOV mayor hará que más del mundo sea visible, 
	pero también hará que los objetos parezcan más pequeños y distorsionados en los bordes.*/
	glm::vec3 radio; //radio de rotacion

	Camera(ProjectionType type,glm::vec3 position, glm::vec3 up, glm::vec3 lookAt);

	glm::mat4 getProjection();
	glm::mat4 getView();
	void setLookAt(glm::vec3 lookAt);

	float getAngle();
	glm::vec3 getRadio();

	void computeProjectionMatrix();
	void computeViewMatrix();


	glm::vec4 getPosition() override;
	void setPosition(glm::vec4 position) override;

	glm::vec4 getRotation() override;
	void setRotation(glm::vec4 rotation) override;

	glm::vec4 getScaling() override;
	void setScaling(glm::vec4 scaling) override;

	glm::mat4 getModelMtx() override;
	void setModelMtx(glm::mat4 modelMtx) override;

	void computeModelMatrix() override;

};

