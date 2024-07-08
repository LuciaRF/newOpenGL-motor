#include "TrianguloRot.h"
#include "iostream"

TrianguloRot::TrianguloRot()
{
	Mesh3D triangulo;

	vector<vertex_t> vertices;
	vertices.resize(3);
	vertices[0].pos = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f); //izquierda
	vertices[1].pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f); //arriba
	vertices[2].pos = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f); //derecha

	triangulo.addVertex(vertices[0]);
	triangulo.addVertex(vertices[1]);
	triangulo.addVertex(vertices[2]);

	setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	setRotation(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	setScaling(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	setModelMtx(glm::mat4(1.0f));
}

void TrianguloRot::step(double deltaTime)
{
	float velocity = 0.05f;
	glm::vec4 rotacionTriangulo = getRotation();
	rotacionTriangulo.y += deltaTime * velocity;
	setRotation(rotacionTriangulo);

	if (System::inputManager->isPressed(GLFW_KEY_E))
	{
		System::exit();
	}
}