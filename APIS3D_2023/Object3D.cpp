#include "Object3D.h"

//Entity

glm::vec4 Object3D::getPosition()
{
	return position;
}

void Object3D::setPosition(glm::vec4 position)
{
	this->position = position;
}

glm::vec4 Object3D::getRotation()
{
	return rotation;
}

void Object3D::setRotation(glm::vec4 rotation)
{
	this->rotation = rotation;
}

glm::vec4 Object3D::getScaling()
{
	return scaling;
}

void Object3D::setScaling(glm::vec4 scaling)
{
	this->scaling = scaling;
}

glm::mat4 Object3D::getModelMtx()
{
	return modelMtx;
}

void Object3D::setModelMtx(glm::mat4 modelMtx)
{
	this->modelMtx = modelMtx;
}

void Object3D::computeModelMatrix()
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position));
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); //modelo que rota, angulo por el que rota, rotacion
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scaling));

	this->modelMtx = model;
}

void Object3D::step(double deltaTime)
{
	//todavía me queda saber que tiene que hacer step
}

//Object

Mesh3D& Object3D::getMesh()
{
	return this->mesh;
}

void Object3D::setMesh(Mesh3D& mesh)
{
	this->mesh = mesh;

}

int Object3D::getTipo()
{
	return tipo;
}

void Object3D::setTipo(int tipo)
{
	this->tipo = tipo;

}

void Object3D::loadDataFromFile(string file)
{

}