#include "Entity.h"

glm::vec4 Entity::getPosition()
{
	return position;
}

void Entity::setPosition(glm::vec4 position)
{
	this->position = position;
}

glm::vec4 Entity::getRotation()
{
	return rotation;
}

void Entity::setRotation(glm::vec4 rotation)
{
	this->rotation = rotation;
}

glm::vec4 Entity::getScaling()
{
	return scaling;
}

void Entity::setScaling(glm::vec4 scaling)
{
	this->scaling = scaling;
}

glm::mat4 Entity::getModelMtx()
{
	return modelMtx;
}

void Entity::setModelMtx(glm::mat4 modelMtx)
{
	this->modelMtx = modelMtx;
}

void Entity::computeModelMatrix()
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position));
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); //modelo que rota, angulo por el que rota, rotacion
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scaling));

	this->modelMtx = model;
}