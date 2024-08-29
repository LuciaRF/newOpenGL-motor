#include "CubeTex.h"

CubeTex::CubeTex(const char* fileName)
{
	Mesh3D* cubo1 = new Mesh3D(); 
	setMesh(*cubo1);

	vector<vertex_t> vertices;
	vertices.resize(16);

	vertices[0].pos = glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f); //trasero-izq-bajo
	vertices[1].pos = glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f); //trasero-izq-arriba
	vertices[2].pos = glm::vec4(0.5f, 0.5f, -0.5f, 1.0f); //trasero-derecha-arriba
	vertices[3].pos = glm::vec4(0.5f, -0.5f, -0.5f, 1.0f); //trasero-derecha-abajo

	vertices[4].pos = glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f); //frente-izq-bajo
	vertices[5].pos = glm::vec4(-0.5f, 0.5f, 0.5f, 1.0f); //frente-izq-arriba
	vertices[6].pos = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f); //frente-derecha-arriba
	vertices[7].pos = glm::vec4(0.5f, -0.5f, 0.5f, 1.0f); //frente-derecha-abajo

	vertices[8].pos = glm::vec4(0.5f, -0.5f, 0.5f, 1.0f); //frente-izq-bajo 2
	vertices[9].pos = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f); //frente-izq-arriba 2
	vertices[10].pos = glm::vec4(0.5f, 0.5f, -0.5f, 1.0f); //frente-derecha-arriba 2
	vertices[11].pos = glm::vec4(0.5f, -0.5f, -0.5f, 1.0f); //frente-derecha-abajo 2

	vertices[12].pos = glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f); //frente-izq-bajo 2
	vertices[13].pos = glm::vec4(-0.5f, 0.5f, 0.5f, 1.0f); //frente-izq-arriba 2
	vertices[14].pos = glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f); //frente-derecha-arriba 2
	vertices[15].pos = glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f); //frente-derecha-abajo 2


	vertices[0].vText = glm::vec2(0.0f, 0.0f);
	vertices[1].vText = glm::vec2(0.0f, 1.0f);
	vertices[2].vText = glm::vec2(1.0f, 1.0f);
	vertices[3].vText = glm::vec2(1.0f, 0.0f);

	vertices[4].vText = glm::vec2(0.0f, 0.0f);
	vertices[5].vText = glm::vec2(0.0f, 1.0f);
	vertices[6].vText = glm::vec2(1.0f, 1.0f);
	vertices[7].vText = glm::vec2(1.0f, 0.0f);

	vertices[8].vText = glm::vec2(0.0f, 0.0f);
	vertices[9].vText = glm::vec2(0.0f, 1.0f);
	vertices[10].vText = glm::vec2(1.0f, 1.0f);
	vertices[11].vText = glm::vec2(1.0f, 0.0f);

	vertices[12].vText = glm::vec2(0.0f, 0.0f);
	vertices[13].vText = glm::vec2(0.0f, 1.0f);
	vertices[14].vText = glm::vec2(1.0f, 1.0f);
	vertices[15].vText = glm::vec2(1.0f, 0.0f);

	getMeshes()[0]->addVertex(vertices[0]);
	getMeshes()[0]->addVertex(vertices[1]);
	getMeshes()[0]->addVertex(vertices[2]);
	getMeshes()[0]->addVertex(vertices[3]);	
	getMeshes()[0]->addVertex(vertices[4]);
	getMeshes()[0]->addVertex(vertices[5]);
	getMeshes()[0]->addVertex(vertices[6]);
	getMeshes()[0]->addVertex(vertices[7]);	
	getMeshes()[0]->addVertex(vertices[8]);	
	getMeshes()[0]->addVertex(vertices[9]);
	getMeshes()[0]->addVertex(vertices[10]);
	getMeshes()[0]->addVertex(vertices[11]);
	getMeshes()[0]->addVertex(vertices[12]);	
	getMeshes()[0]->addVertex(vertices[13]);
	getMeshes()[0]->addVertex(vertices[14]);
	getMeshes()[0]->addVertex(vertices[15]);

	/*Caras frontales - sentido horario*/
	/*Caras traseras - sentido antihorario*/

	getMeshes()[0]->addTriangle(0, 1, 2);
	getMeshes()[0]->addTriangle(0, 2, 3);
	getMeshes()[0]->addTriangle(4, 5, 6);
	getMeshes()[0]->addTriangle(4, 6, 7);
	
	getMeshes()[0]->addTriangle(8, 9, 10); //no se pueden repetir indices aunque sean el mismo punto del triangulo
	getMeshes()[0]->addTriangle(8, 10, 11);
	getMeshes()[0]->addTriangle(12, 13, 14);
	getMeshes()[0]->addTriangle(12, 14, 15);

	Mesh3D* cubo2 = new Mesh3D();
	setMesh(*cubo2);

	vector<vertex_t> vertices2;
	vertices2.resize(8);

	vertices2[0].pos = glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f); //izq-bajo
	vertices2[1].pos = glm::vec4(-0.5f, -0.5f, 0.5f, 1.0f); //izq-arriba
	vertices2[2].pos = glm::vec4(0.5f, -0.5f, 0.5f, 1.0f); //derecha-arriba
	vertices2[3].pos = glm::vec4(0.5f, -0.5f, -0.5f, 1.0f); //derecha-abajo	

	vertices2[4].pos = glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f); //izq-bajo
	vertices2[5].pos = glm::vec4(-0.5f, 0.5f, 0.5f, 1.0f); //izq-arriba
	vertices2[6].pos = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f); //derecha-arriba
	vertices2[7].pos = glm::vec4(0.5f, 0.5f, -0.5f, 1.0f); //derecha-abajo	

	vertices2[0].vText = glm::vec2(0.0f, 0.0f);
	vertices2[1].vText = glm::vec2(0.0f, 1.0f);
	vertices2[2].vText = glm::vec2(1.0f, 1.0f);
	vertices2[3].vText = glm::vec2(1.0f, 0.0f);
	vertices2[4].vText = glm::vec2(0.0f, 0.0f);
	vertices2[5].vText = glm::vec2(0.0f, 1.0f);
	vertices2[6].vText = glm::vec2(1.0f, 1.0f);
	vertices2[7].vText = glm::vec2(1.0f, 0.0f);

	getMeshes()[1]->addVertex(vertices2[0]);
	getMeshes()[1]->addVertex(vertices2[1]);
	getMeshes()[1]->addVertex(vertices2[2]);
	getMeshes()[1]->addVertex(vertices2[3]);
	getMeshes()[1]->addVertex(vertices2[4]);
	getMeshes()[1]->addVertex(vertices2[5]);
	getMeshes()[1]->addVertex(vertices2[6]);
	getMeshes()[1]->addVertex(vertices2[7]);

	getMeshes()[1]->addTriangle(0, 1, 2);
	getMeshes()[1]->addTriangle(0, 2, 3);
	getMeshes()[1]->addTriangle(6, 5, 4);
	getMeshes()[1]->addTriangle(6, 4, 7);

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

		Texture* texture2 = FactoryEngine::getNewTexture("data/top.png"); //revisar si ya se hace solo
		getMeshes()[1]->setMaterial(FactoryEngine::getNewMaterial());
		getMeshes()[1]->getMaterial()->setTexture(texture2);

		getMeshes()[1]->getMaterial()->addSrc("data/program.vertex", renderTypes_e::vertex);
		getMeshes()[1]->getMaterial()->addSrc("data/program.fragment", renderTypes_e::fragment);
		getMeshes()[1]->getMaterial()->loadPrograms();
	}
}

void CubeTex::step(float deltaTime)
{
	if (System::inputManager->isPressed(GLFW_KEY_E))
	{
		System::exit();
	}
}

//void Object3D::loadDataFromFile(const char* fileName)
//{
//	pugi::xml_document doc;
//	pugi::xml_parse_result result = doc.load_file(fileName);
//	if (result)
//	{
//		pugi::xml_node buffersNode = doc.child("mesh").child("buffers");
//
//		for (pugi::xml_node bufferNode = buffersNode.child("buffer");
//			bufferNode;
//			bufferNode = bufferNode.next_sibling("buffer"))
//		{
//			//Iteramos por todos los buffers
//			this->text = new texture(bufferNode.child("material").child("texture").text().as_string());
//
//			this->prg = new program();
//			this->prg->addShader(bufferNode.child("material").child("vShader").text().as_string());
//			this->prg->addShader(bufferNode.child("material").child("fShader").text().as_string());
//
//			this->prg->linkProgram();
//
//			std::vector<float> vList = splitString<float>(bufferNode.child("coords").text().as_string(), ',');
//			std::vector<float> tcList = splitString<float>(bufferNode.child("texCoords").text().as_string(), ',');
//
//			auto coord = vList.begin();
//			auto texCoord = tcList.begin();
//
//			while (coord != vList.end() && texCoord != tcList.end())
//			{
//				vertex_t v;
//				v.pos.x = *coord++;
//				v.pos.y = *coord++;
//				v.pos.z = *coord++;
//				v.pos.w = 1.0f;
//
//				v.textCoord.x = *texCoord++;
//				v.textCoord.y = *texCoord++;
//
//				v.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
//
//				this->vertices.push_back(v);
//			}
//
//			this->indexes = splitString<unsigned int>(bufferNode.child("indices").text().as_string(), ',');
//		}
//	}
//	else
//	{
//		//No se ha podido cargar
//		std::cout << result.description() << std::endl;
//	}
//}
//
//template <typename T> //sirve para dividir las , de la lista de msh
//std::vector<T> splitString(const std::string& str, char delim) {
//	std::vector<T> elems;
//	std::stringstream sstream(str);
//	std::string item;
//	T tipoDato;
//	if (str != "") {
//		while (std::getline(sstream, item, delim))
//		{
//			std::istringstream str(item);
//			str >> tipoDato;
//			elems.push_back(tipoDato);
//		}
//	}
//	return elems;
//}
