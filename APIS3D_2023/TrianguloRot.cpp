#include "TrianguloRot.h"

TrianguloRot::TrianguloRot()
{
	//Mesh3D triangulo = getMesh();

	vector<vertex_t> vertices;
	vertices.resize(3);
	vertices[0].pos = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f); //izquierda
	vertices[1].pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f); //arriba
	vertices[2].pos = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f); //derecha

	getMesh().addVertex(vertices[0]);
	getMesh().addVertex(vertices[1]);
	getMesh().addVertex(vertices[2]);
	//triangulo.addVertex(vertices[3]);

	getMesh().addTriangle(0, 1, 2);

	setPosition(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	setRotation(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	setScaling(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	setModelMtx(glm::mat4(1.0f));

	if (FactoryEngine::getSelectedGraphicsBackend() == FactoryEngine::GL4)
	{
		getMesh().setMaterial(FactoryEngine::getNewMaterial());
		auto prg = getMesh().getMaterial()->getProgram();
		//prg.
		getMesh().getMaterial()->addSrc("data/program.vertex", renderTypes_e::vertex);
		getMesh().getMaterial()->addSrc("data/program.fragment", renderTypes_e::fragment);
		getMesh().getMaterial()->loadPrograms();
	}
}

void TrianguloRot::step(double deltaTime)
{
	float velocity = 0.4f;
	glm::vec4 rotacionTriangulo = getRotation();
	rotacionTriangulo.y += deltaTime * velocity;
	setRotation(rotacionTriangulo);

	if (System::inputManager->isPressed(GLFW_KEY_E))
	{
		System::exit();
	}
}