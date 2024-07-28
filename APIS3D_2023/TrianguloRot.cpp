#include "TrianguloRot.h"

TrianguloRot::TrianguloRot()
{
	Mesh3D triangulo = getMesh();

	vector<vertex_t> vertices;
	vertices.resize(3);
	vertices[0].pos = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f); //izquierda
	vertices[1].pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f); //arriba
	vertices[2].pos = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f); //derecha

	//vertices.resize(4);
	//vertices[0].pos = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f); //izquierda
	//vertices[1].pos = glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f); //arriba
	//vertices[2].pos = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f); // 1    2
	//vertices[3].pos = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f); // 0    3
	

	triangulo.addVertex(vertices[0]);
	triangulo.addVertex(vertices[1]);
	triangulo.addVertex(vertices[2]);
	//triangulo.addVertex(vertices[3]);

	triangulo.addTriangle(0, 1, 2);

	setPosition(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	setRotation(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	setScaling(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	setModelMtx(glm::mat4(1.0f));

	if (FactoryEngine::getSelectedGraphicsBackend() == FactoryEngine::GL4)
	{
		triangulo.setMaterial(FactoryEngine::getNewMaterial());
		triangulo.getMaterial()->addSrc("data/program.vertex", renderTypes_e::vertex);
		triangulo.getMaterial()->addSrc("data/program.fragment", renderTypes_e::fragment);
	}
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