#include "CubeTex.h"

CubeTex::CubeTex(const char* fileName)
{
	Mesh3D* cubo1 = new Mesh3D();
	setMesh(*cubo1);

	vector<vertex_t> vertices;
	vertices.resize(4);
	vertices[0].pos = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f); //izq-bajo
	vertices[1].pos = glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f); //izq-arriba
	vertices[2].pos = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f); //derecha-arriba
	vertices[3].pos = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f); //derecha-abajo

	vertices[0].vText = glm::vec2(0.0f, 0.0f);
	vertices[1].vText = glm::vec2(0.0f, 1.0f);
	vertices[2].vText = glm::vec2(1.0f, 1.0f);
	vertices[3].vText = glm::vec2(1.0f, 0.0f);

	getMeshes()[0]->addVertex(vertices[0]);
	getMeshes()[0]->addVertex(vertices[1]);
	getMeshes()[0]->addVertex(vertices[2]);
	getMeshes()[0]->addVertex(vertices[3]);

	getMeshes()[0]->addTriangle(0, 1, 2);
	getMeshes()[0]->addTriangle(0, 2, 3);

	setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	setRotation(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	setScaling(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	setModelMtx(glm::mat4(1.0f));

	if (FactoryEngine::getSelectedGraphicsBackend() == FactoryEngine::GL4)
	{
		Texture * texture = FactoryEngine::getNewTexture(fileName); //revisar si ya se hace solo
		getMeshes()[0]->setMaterial(FactoryEngine::getNewMaterial());
		getMeshes()[0]->getMaterial()->setTexture(texture);

		getMeshes()[0]->getMaterial()->addSrc("data/program.vertex", renderTypes_e::vertex);
		getMeshes()[0]->getMaterial()->addSrc("data/program.fragment", renderTypes_e::fragment);
		getMeshes()[0]->getMaterial()->loadPrograms();
	}
}

void CubeTex::step(float deltaTime)
{
	if (System::inputManager->isPressed(GLFW_KEY_E))
	{
		System::exit();
	}
}
