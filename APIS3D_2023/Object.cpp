#include "Object.h"

Mesh3D* Object::getMesh()
{
	return mesh;
}

void Object::setMesh(Mesh3D* mesh)
{
	this->mesh = mesh;

}

int Object::getTipo()
{
	return tipo;
}

void Object::setTipo(int tipo)
{
	this->tipo = tipo;

}